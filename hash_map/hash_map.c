#include "hash_map.h"

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
	hash_entry **entry;
	uint32_t size;
	uint32_t used;
}hash_table;

typedef struct hash_map
{
	hash_funcs funcs;
	hash_table table[2];
	uint32_t tbl_idx;
	uint32_t rehashidx;
	float load_factor;
} hash_map;

hash_map_t create_hashmap(hash_funcs* funcs, uint32_t hash_size)
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
	p_hashmap->table[0].entry = (hash_entry **)malloc(sizeof(hash_entry *) * hash_size);
	if(0 == p_hashmap->table[0].entry)
	{
		free(p_hashmap);
		return 0;
	}
	p_hashmap->table[0].size = hash_size;
	p_hashmap->table[0].used = 0;
	memset(p_hashmap->table[0].entry, 0, sizeof(hash_entry *) * hash_size);

	memcpy(&p_hashmap->funcs, funcs, sizeof(hash_funcs));
	p_hashmap->tbl_idx = 0;
	p_hashmap->rehashidx = 0;
	p_hashmap->load_factor = 0.8f;

	return p_hashmap;
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
