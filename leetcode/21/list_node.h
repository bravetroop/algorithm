#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

void printList(struct ListNode* l);

#ifdef __cplusplus
}
#endif

#endif
