#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {

    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        int index = 0;
        for (index = 0; index < n && fast; ++index) {
            fast = fast->next;
        }

        //倒数索引等于或超过链表实际长度
        if (fast == NULL) {
            head = slow->next;
            delete slow;
            return head;
        }

        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* tmp = slow->next->next;
        delete slow->next;
        slow->next = tmp;

        return head;
    }
};