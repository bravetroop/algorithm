#include "hash_map_priv.h"

hash_map_t create_hash_map(hash_funcs* funcs, uint32_t hash_size)
{
	hash_map_t p_hashmap = 0;

	if ((0 == funcs) || (0 == hash_size)) {
		return 0;
	}

	p_hashmap = (hash_map_t) malloc(sizeof(hash_map));
	if (0 == p_hashmap) {
		return 0;
	}

	hash_size = (hash_size + 0x03) & ~0x03;

	p_hashmap->table[0].size = hash_size;
	p_hashmap->table[0].used = 0;
	p_hashmap->table[0].bkt = (hash_entry **) malloc(sizeof(hash_entry *) * hash_size);
	if (0 == p_hashmap->table[0].bkt) {
		free(p_hashmap);
		return 0;
	}
	memset(p_hashmap->table[0].bkt, 0, sizeof(hash_entry *) * hash_size);
	memset(&p_hashmap->table[1], 0, sizeof(hash_table));

	p_hashmap->cur_tbl_idx = 0;
	p_hashmap->rehashing = 0;
	p_hashmap->rehashidx = 0;
	p_hashmap->load_factor = 0.8f;
	memcpy(&p_hashmap->funcs, funcs, sizeof(hash_funcs));

	return p_hashmap;
}

int32_t insert_hash_map(hash_map_t hash_map, void* key, void* value)
{
	hash_entry* p_hash_entry = 0;

	if( (0 == hash_map) || (0 == key) || (0 == value) ) {
		return -1;
	}

	p_hash_entry = (hash_entry*)malloc(sizeof(hash_entry));
	if(0 == p_hash_entry) {
		return -2;
	}
	p_hash_entry->key = hash_map->funcs.key_dump(key);
	p_hash_entry->u.value = hash_map->funcs.value_dump(value);
	p_hash_entry->next = 0;

	if(0 != insert_node_in_bkt(hash_map, p_hash_entry)) {
		hash_map->funcs.key_destruct(p_hash_entry->key);
		hash_map->funcs.value_destruct(p_hash_entry->u.value);
		free(p_hash_entry);
		return -3;
	}

	return 0;
}

int32_t insert_node_in_bkt(hash_map_t hash_map, hash_entry* p_hash_entry)
{
	uint32_t bkt_idx = 0;
	uint8_t curr_tbl_idx = 0;
	hash_entry* p = 0, *p_tmp = 0;

	if((0 == hash_map) || (0 == p_hash_entry)) {
		return -1;
	}

	curr_tbl_idx = get_curr_tbl_idx(hash_map);
	bkt_idx = hash_map->funcs.hash_func(p_hash_entry->key) &(hash_map->table[curr_tbl_idx].size -1);

	p = p_tmp = hash_map->table[curr_tbl_idx].bkt[bkt_idx];
	if(0 == p) {
		hash_map->table[curr_tbl_idx].bkt[bkt_idx] = p_hash_entry;
	} else {
		while(p_tmp) {
			if(0 == hash_map->funcs.key_cmp(p_hash_entry->key, p_tmp->key)) {
				//already exist
				return -2;
			}
			p = p_tmp;
			p_tmp = p_tmp->next;
		}

		p->next = p_hash_entry; //insert into last
	}

	++hash_map->table[curr_tbl_idx].used;

	return 0;
}

void* find_value(hash_map_t hash_map, void* key)
{
	uint8_t tbl_idx = 0;
	uint32_t bkt_idx = 0;
	void* value = 0;

	if( !hash_map || !key ) {
		return 0;
	}

	if(hash_map->rehashing) {
		tbl_idx = get_idle_tbl_idx(hash_map);
		bkt_idx = hash_map->funcs.hash_func(key) & (hash_map->table[tbl_idx].size - 1);
		if(bkt_idx >= hash_map->rehashidx) {
			value = find_value_in_bkt(hash_map, hash_map->table[tbl_idx].bkt[bkt_idx], key);
			if(value)
				return value;
		}
	}

	tbl_idx = get_curr_tbl_idx(hash_map);
	bkt_idx = hash_map->funcs.hash_func(key) &(hash_map->table[tbl_idx].size -1);
	value = find_value_in_bkt(hash_map, hash_map->table[tbl_idx].bkt[bkt_idx], key);

	return value;
}

void* find_value_in_bkt(hash_map_t hash_map, hash_entry * bkt, void* key)
{
	void* pval = 0;
	hash_entry* pnode = 0;

	for (pnode = bkt; 0 != pnode; pnode = pnode->next) {
		if (0 == hash_map->funcs.key_cmp(pnode->key, key)) {
			pval = pnode->u.value;
			break;
		}
	}

	return pval;
}

uint32_t hash_map_size(hash_map_t hash_map)
{
	uint8_t idle_tbl_idx = 0;
	uint8_t curr_tbl_idx = 0;
	uint32_t map_size = 0;

	if(0 == hash_map) {
		return 0;
	}

	if(hash_map->rehashing) {
		idle_tbl_idx = get_idle_tbl_idx(hash_map);
		map_size += hash_map->table[idle_tbl_idx].used;
	}

	curr_tbl_idx = get_curr_tbl_idx(hash_map);
	map_size += hash_map->table[curr_tbl_idx].used;

	return map_size;
}

void set_load_refactor(hash_map_t hash_map, float factor)
{
	if(factor && hash_map)
		hash_map->load_factor = factor;
}

int32_t free_hash_map(hash_map_t hash_map)
{
	uint8_t cur_tbl_idx = 0;
	uint8_t idl_tbl_idx = 0;

	if(0 == hash_map) {
		return -1;
	}

	idl_tbl_idx = get_idle_tbl_idx(hash_map);
	free_hash_table(hash_map, idl_tbl_idx);

	cur_tbl_idx = get_curr_tbl_idx(hash_map);
	free_hash_table(hash_map, cur_tbl_idx);

	free(hash_map);
	return 0;
}

void free_hash_table(hash_map_t hash_map, uint8_t tbl_idx)
{
	uint32_t bkt_idx = 0;
	uint32_t bkt_size = 0;

	if( (0 == hash_map) || (tbl_idx > 1)) {
		return;
	}

	if(hash_map->table[tbl_idx].bkt) {
		bkt_size = hash_map->table[tbl_idx].size;
		for(bkt_idx = 0; bkt_idx < bkt_size; ++bkt_idx) {
			hash_entry* p = hash_map->table[tbl_idx].bkt[bkt_idx];
			hash_entry* q = p;
			while(p) {
				q = p->next;
				hash_map->funcs.key_destruct(p->key);
				hash_map->funcs.value_destruct(p->u.value);
				free(p);
				p = q;
			}
		}

		free(hash_map->table[tbl_idx].bkt);
		hash_map->table[tbl_idx].bkt = 0;
	}
}

uint8_t get_curr_tbl_idx(hash_map_t hash_map)
{
	if(0 == hash_map) {
		return 0;
	}

	return (0 == hash_map->cur_tbl_idx) ? 0 : 1;
}

uint8_t get_idle_tbl_idx(hash_map_t hash_map)
{
	if(0 == hash_map) {
		return 0;
	}

	return (0 == hash_map->cur_tbl_idx) ? 1 : 0;
}
