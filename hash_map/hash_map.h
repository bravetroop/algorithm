#ifndef __HASH_MAP__
#define __HASH_MAP__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct hash_map* hash_map_t;

typedef struct
{
	uint32_t (*hash_func)(void* key);
	void* (*key_dump)(void* key);
	void* (*value_dump)(void* value);
	int32_t (*key_cmp)(void* key1, void* key2);
	void (*key_destruct)(void* key);
	void (*value_destruct)(void* value);
}hash_funcs;

hash_map_t create_hash_map(hash_funcs* funcs, uint32_t hash_size);

int32_t insert_hash_map(hash_map_t hash_map, void* key, void* value);

void* find_value(hash_map_t hash_map, void* key);

uint32_t hash_map_size(hash_map_t hash_map);

void set_load_refactor(hash_map_t hash_map, float factor);

int32_t free_hash_map(hash_map_t hash_map);

#ifdef __cplusplus
}
#endif

#endif
