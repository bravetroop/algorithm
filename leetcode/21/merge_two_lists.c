#include "list_node.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* p = l1;
	struct ListNode* q = l2;
	struct ListNode* tmp = 0;
	struct ListNode* head = 0;
	struct ListNode* current = 0;

	if(0 == l1)
	{
		return l2;
	}
	else if(0 == l2)
	{
		return l1;
	}

	while(p && q)
	{
		if(p->val <= q->val)
		{
			tmp = p;
			p = p->next;
		}
		else
		{
			tmp = q;
			q = q->next;
		}

		if(0 == head)
		{
			head = tmp;
		}
		else
		{
			current->next = tmp;
		}
		current = tmp;
	}

	if(p)
	{
		current->next = p;
	}
	else
	{
		current->next = q;
	}

	return head;
}


void printList(struct ListNode* l)
{
	while(l)
	{
		printf("%d ", l->val);
		l = l->next;
	}

	printf("\n");
}
