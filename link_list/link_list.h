#include <stdio.h>
#include <stdint.h>

typedef struct list_node
{
	struct list_node* pnext;
	void* pdata;
}list_node_t;

typedef struct list_iterator
{
	list_node_t* pnode;
}list_iterator_t;

typedef struct link_list
{
	list_node_t *phead;
	list_node_t *ptail;

	uint32_t ulsize;
}link_list_t;

link_list_t* create_list();

int add_list(link_list_t*, void*);

uint32_t get_list_size(link_list_t*);

list_iterator_t get_list_iterator(link_list_t*);

list_iterator_t get_next_iterator(list_iterator_t);

void* get_node_data(list_iterator_t);

link_list_t* reverse_list(link_list_t*);
