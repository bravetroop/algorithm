#include "link_list.h"

link_list_t* reverse_list(link_list_t* p_head)
{
    link_list_t *p = NULL, *q = NULL, *p_next = NULL;
    if(NULL == p_head)
    {
    	return p_head;
    }

    p = p_head;
    p_next = p->p_next;
    while(p_next)
    {
		q = p_next->p_next;
		p_next->p_next = p;
		p = p_next;
		p_next = q;
    }
    p_head->p_next = NULL;

    return p;
}

void print_list(link_list_t* p_head)
{
    if(NULL == p_head)
    {
    	printf("empty list");
    }

    while(p_head)
    {
		printf("%d\t", p_head->data);
		p_head = p_head->p_next;
    }

    printf("\n");
}
