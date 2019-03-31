#include <stdio.h>

typedef struct link_list
{
    int data;
    struct link_list_t* p_next;
}link_list_t;

link_list_t* reverse_list(link_list_t*);

void print_list(link_list_t* p_head);
	
