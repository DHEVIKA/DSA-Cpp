/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // two pointers
        ListNode* firstPtr = dummy;
        ListNode* secondPtr = dummy;

        // move second pointer n steps ahead
        for (int i = 0; i < n; i++) {
            secondPtr = secondPtr->next;
        }

        // move both until second reaches last node
        while (secondPtr->next != nullptr) {
            firstPtr = firstPtr->next;
            secondPtr = secondPtr->next;
        }

        // delete nth node
        firstPtr->next = firstPtr->next->next;

        return dummy->next;
    }
};