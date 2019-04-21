#include "link_list.h"

link_list_t* create_list()
{
	link_list_t* p = NULL;
	p = (link_list_t*)malloc(sizeof(link_list_t));
	if(NULL != p)
	{
		p->phead = NULL;
		p->ptail = NULL;
		p->ulsize = 0;
	}
	return p;
}

int add_list(link_list_t* plist, void* pdata)
{
	list_node_t* pnode = NULL;

	if( (NULL == plist)
			|| (NULL == pdata))
	{
		return -1;
	}

	pnode = (list_node_t*)malloc(sizeof(list_node_t));
	if(NULL == pnode)
	{
		return -2;
	}

	pnode->pdata = pdata;
	pnode->pnext = NULL;

	if(NULL == plist->phead)
	{
		plist->phead = pnode;
		plist->ptail = pnode;
	}
	else
	{
		plist->ptail->pnext = pnode;
	}

	plist->ptail = pnode;
	++plist->ulsize;

	return 0;
}

uint32_t get_list_size(link_list_t* plist)
{
	if(NULL == plist)
	{
		return 0;
	}

	return plist->ulsize;
}

list_iterator_t get_list_iterator(link_list_t* plist)
{
	list_iterator_t list_it = {0};

	if(NULL != plist)
	{
		list_it.pnode = plist->phead;
	}

	return list_it;
}

list_iterator_t get_next_iterator(list_iterator_t list_it)
{
	list_iterator_t it = {0};
	if(list_it.pnode)
	{
		it.pnode = list_it.pnode->pnext;
	}
	return it;
}

void* get_data(list_iterator_t list_it)
{
	if(list_it.pnode)
	{
		return list_it.pnode->pdata;
	}

	return NULL;
}

/*
link_list_t* reverse_list(link_list_t* plist)
{
    link_list_t *p = NULL, *q = NULL, *p_next = NULL;
    if(NULL == plist)
    {
    	return plist;
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
*/
