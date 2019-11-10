#include <stdio.h>
#include "list_node.h"

int main()
{
	struct ListNode l1[3] = {0};
	struct ListNode l2[4] = {0};
	struct ListNode *pList = 0;

	l1[0].val = 5; l1[0].next = &l1[1];
	l1[1].val = 8; l1[1].next = &l1[2];
	l1[2].val = 10; l1[2].next = 0;


	l2[0].val = 1; l2[0].next = &l2[1];
	l2[1].val = 6; l2[1].next = &l2[2];
	l2[2].val = 7; l2[2].next = &l2[3];
	l2[3].val = 12; l2[3].next = 0;

	pList = mergeTwoLists(l1, l2);

	printList(pList);
	return 0;
}
