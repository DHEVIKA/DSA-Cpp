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
    bool hasCycle(ListNode *head) {
// slow & fast pointer patters for linked list cycle
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != nullptr && fast->next != nullptr){ 
            slow = slow->next; // 1 step ahead for slow ptr 
            fast = fast->next->next; // 2 steps ahead for fast ptr
            if(slow == fast)// to detect cycle (slow meets fast ) cycle detected
                return true;
        }
        
        
        return false;
    }
};