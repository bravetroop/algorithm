#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

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

hash_map_t create_hashmap(hash_funcs* funcs, uint32_t hash_size);

uint32_t hash_map_size(hash_map_t hash_map);

#ifdef __cplusplus
}
#endif

#endif
