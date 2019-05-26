#include "hash_map.h"

#define HASH_INDEX_INVALID 0xFFFFFFFF

typedef struct hash_entry
{
	void* key;
	union
	{
		void* value;
		uint64_t tu64;
		int64_t ts64;
	}u;
	struct hash_entry* next;
}hash_entry;

typedef struct
{
	hash_entry **bkt;
	uint32_t size;
	uint32_t used;
}hash_table;

typedef struct hash_map
{
	hash_funcs funcs;
	hash_table table[2];
	uint8_t tbl_idx;
	uint8_t rehashing;
	uint16_t reserved;
	uint32_t rehashidx;
	float load_factor;
} hash_map;

static void* find_value_in_bkt(hash_map_t hash_map, hash_entry * bkt_entry, void* key);
static int insert_value_in_bkt(hash_map_t hash_map, void* key, void* value);

hash_map_t create_hash_map(hash_funcs* funcs, uint32_t hash_size)
{
	hash_map_t p_hashmap = 0;
	if( (0 == funcs)
			|| (0 == hash_size) )
	{
		return 0;
	}

	p_hashmap = (hash_map_t)malloc(sizeof(hash_map));
	if(0 == p_hashmap)
	{
		return 0;
	}

	hash_size = (hash_size + 0x03) &  ~0x03;

	p_hashmap->table[0].size = hash_size;
	p_hashmap->table[0].used = 0;
	p_hashmap->table[0].bkt = (hash_entry **)malloc(sizeof(hash_entry *) * hash_size);
	if(0 == p_hashmap->table[0].bkt)
	{
		free(p_hashmap);
		return 0;
	}
	memset(p_hashmap->table[0].bkt, 0, sizeof(hash_entry *) * hash_size);

	memcpy(&p_hashmap->funcs, funcs, sizeof(hash_funcs));
	p_hashmap->tbl_idx = 0;
	p_hashmap->rehashing = 0;
	p_hashmap->rehashidx = HASH_INDEX_INVALID;
	p_hashmap->load_factor = 0.8f;

	return p_hashmap;
}

int32_t insert_hash_map(hash_map_t hash_map, void* key, void* value)
{
	if( !hash_map || !key || !value )
	{
		return -1;
	}

	if(find_value(hash_map, key))
	{
		return -2;
	}

	if(0 != insert_value_in_bkt(hash_map, key, value))
	{
		return -3;
	}

	return 0;
}

void* find_value(hash_map_t hash_map, void* key)
{
	uint8_t tbl_idx = 0;
	uint32_t bkt_idx = 0;
	void* value = 0;

	if( !hash_map || !key )
	{
		return 0;
	}

	tbl_idx = hash_map->tbl_idx;

	//find in old hash map
	if(hash_map->rehashing)
	{
		uint8_t old_tbl = (0 == tbl_idx) ? 1 : 0;

		bkt_idx = hash_map->funcs.hash_func(key) & (hash_map->table[old_tbl].size - 1);
		if(bkt_idx >= hash_map->rehashidx)
		{
			value = find_value_in_bkt(hash_map, hash_map->table[old_tbl].bkt[bkt_idx], key);
			if(value)
				return value;
		}
	}

	//find in current hash map
	bkt_idx = hash_map->funcs.hash_func(key) &(hash_map->table[tbl_idx].size -1);
	value = find_value_in_bkt(hash_map, hash_map->table[tbl_idx].bkt[bkt_idx], key);

	return value;
}

int insert_value_in_bkt(hash_map_t hash_map, void* key, void* value)
{
	uint8_t tbl_idx = 0;
	uint32_t bkt_idx = 0;
	hash_entry * bkt_node = 0;
	hash_entry * new_node = 0;

	if( !hash_map || !key || !value )
	{
		return -1;
	}

	tbl_idx = hash_map->tbl_idx;
	bkt_idx = hash_map->funcs.hash_func(key) &(hash_map->table[tbl_idx].size -1);
	bkt_node = hash_map->table[tbl_idx].bkt[bkt_idx];

	new_node = (hash_entry*)malloc(sizeof(hash_entry));
	if(!new_node)
	{
		return -2;
	}

	new_node->key = hash_map->funcs.key_dump(key);
	new_node->u.value = hash_map->funcs.value_dump(value);
	new_node->next = bkt_node;

	hash_map->table[tbl_idx].bkt[bkt_idx] = new_node;
	++hash_map->table[tbl_idx].used;

	return 0;
}

void* find_value_in_bkt(hash_map_t hash_map, hash_entry * bkt, void* key)
{
	void* pval = 0;
	hash_entry* pnode = 0;

	if(!bkt || !key || !hash_map
			|| !hash_map->funcs.key_cmp)
	{
		return pval;
	}

	for(pnode = bkt; 0 != pnode; pnode = pnode->next)
	{
		if(0 == hash_map->funcs.key_cmp(pnode->key, key))
		{
			pval = pnode->u.value;
			break;
		}
	}

	return pval;
}

uint32_t hash_map_size(hash_map_t hash_map)
{
	if( (0 == hash_map)
			|| (hash_map->tbl_idx > 1))
	{
		return 0;
	}

	return hash_map->table[hash_map->tbl_idx].used;
}

void set_load_refactor(hash_map_t hash_map, float factor)
{
	if(factor && hash_map)
		hash_map->load_factor = factor;
}
