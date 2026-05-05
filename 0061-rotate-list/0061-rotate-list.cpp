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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // if head = 0 ; head next value is null ;no rotation (edge cases)  n = 5 ; k=10   10 % 5 = 0 no need to rotate

        int n = 1;
        ListNode* tail = head; // tail pointer is at head and start iterating the tail pointer alone

     // calculating the length

        while (tail->next) {
            tail = tail->next;   
            n++;
        }
        tail->next = head;

    // to reduse k rotations

        k = k % n; /// if the rotation is 5 times u no need to do 5 time('avoiding unnecessary rotaions) .. k % n k-> rotations n->length of list
        // if(k==0) return head;



//convert the linked list into a circular linked list  1->2->3->4->5
//new head will be  n-k (k =2 n = 5 ) 2%5 is 2         3rd node will be 4 

                   // 5 -2 = 3rd node move to it       4->5->1->2->3

        //tail->next = head; // circular
        int steps = n - k -1 ; //n-k-1 steps 5-2-1 = 2 steps (0,1,2) break the 3 -> 4 node reached 3 
        ListNode* newTail = head;                    // 3 as tail 

        while (steps--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = nullptr;

        return newHead;
    }
};
