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
    ListNode* middleNode(ListNode* head) {
// use slow and fast pointer pattern to solve this middle of linked list problem
        if (head == nullptr || head->next == nullptr) return head;//edge case
        ListNode* slow = head; // both slow n fast pointers are at same position as head
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next; // slow moves at 1 time
            fast = fast->next->next; // fast moves at 2 times this is the common approach to find the middl3 eof linked list
        }
        return slow;

        
    }
};

