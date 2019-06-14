#ifndef __HASH_MAP_PRIV_H__
#define __HASH_MAP_PRIV_H__

#include "hash_map.h"

#ifdef __cplusplus
extern "C"
{
#endif

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
	uint8_t cur_tbl_idx;
	uint8_t rehashing;
	uint16_t reserved;
	uint32_t rehashidx;
	float load_factor;
} hash_map;

uint8_t get_curr_tbl_idx(hash_map_t hash_map);
uint8_t get_idle_tbl_idx(hash_map_t hash_map);

void free_hash_table(hash_map_t hash_map, uint8_t tbl_idx);

int32_t insert_node_in_bkt(hash_map_t hash_map, hash_entry* p_hash_entry);

void* find_value_in_bkt(hash_map_t hash_map, hash_entry * bkt, void* key);

#ifdef __cplusplus
}
#endif


#endif
