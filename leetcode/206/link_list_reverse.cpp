/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newListHead = 0;
        ListNode* newNode = 0;
        ListNode* tmpNode = head;

        while(tmpNode)
        {
            newNode = new ListNode(tmpNode->val);
            newNode->next = newListHead;
            newListHead = newNode;

            tmpNode = tmpNode->next;
        }

        return newListHead;
    }
};
