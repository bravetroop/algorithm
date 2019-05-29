#include <stdio.h>
#include <assert.h>
#include "hash_map.h"

uint32_t hash_func(void* key);
void* key_dump(void* key);
void* value_dump(void* value);
int32_t key_cmp(void* key1, void* key2);
void key_destruct(void* key);
void value_destruct(void* value);

int main(int argc, char* argv[])
{
	int32_t index = 0;
	int32_t result = 0;
	void* value = 0;

	uint32_t hash_size = 0;
	hash_map_t hash_map = 0;
	hash_funcs hash_funcs = { hash_func, key_dump, value_dump, key_cmp, key_destruct, value_destruct };

	char* pkey[] = {"H", "He", "Hel", "Hell", "Hello", "Haha"};
	char* pvalue[] = {"W", "Wo", "Wor", "Worl", "World", "bingo"};

	hash_map = create_hash_map(&hash_funcs, 2);
	assert(0 != result);

	set_load_refactor(hash_map, 1.0f);

	for(index = 0; index < sizeof(pkey)/sizeof(pkey[0]); ++index)
	{
		result = insert_hash_map(hash_map, pkey[index], pvalue[index]);
		assert(0 == result);

		hash_size = hash_map_size(hash_map);
		printf("hash_size : %u\n", hash_size);
	}

	result = insert_hash_map(hash_map, pkey[0], pvalue[0]);
	assert(-2 == result);

	char* pkey1 = "Hell";
	value = find_value(hash_map, pkey1);
	assert(0 != value);
	printf("find value = %s\n", value);

	pkey1 = "Haha";
	value = find_value(hash_map, pkey1);
	assert(0 == value);
	printf("find value = %s\n", value);

	free_hash_map(hash_map);

	return 0;
}

uint32_t hash_func(void* key)
{
	int index = 0;
	int str_len = strlen((const char*)key);
	uint32_t hash_value = 0;

	for(index = 0; index < str_len; ++index)
	{
		hash_value += ((char*)key)[index];
	}

	return hash_value;
}

void* str_dump(void* str)
{
	void* pstr_dump = 0;
	int str_len = strlen((const char*)str) ;

	pstr_dump = malloc(str_len + 1);
	if(pstr_dump)
	{
		memcpy(pstr_dump, str, str_len);
		((char*)pstr_dump)[str_len] = 0;
	}

	return pstr_dump;
}

void* key_dump(void* key)
{
	return str_dump(key);
}

void* value_dump(void* value)
{
	return str_dump(value);
}

int32_t key_cmp(void* key1, void* key2)
{
	int index = 0;
	int str_len1 = strlen((const char*)key1);
	int str_len2 = strlen((const char*)key2);

	if(str_len1 != str_len2)
	{
		return 1;
	}

	for(index =0; index< str_len1; ++index)
	{
		if( ((char*)key1)[index] != ((char*)key2)[index] )
		{
			return 1;
		}
	}
	return 0;
}

void key_destruct(void* key)
{
	free(key);
}

void value_destruct(void* value)
{
	free(value);
}
