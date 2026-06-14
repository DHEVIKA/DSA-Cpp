class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // find middle
        while (fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* second = reverse(slow);

        int maxSum = 0;

        // compute twin sum
        while (second) {
            maxSum = max(maxSum, head->val + second->val);
            head = head->next;
            second = second->next;
        }

        return maxSum;
    }
};

//[5->4->2->1] 
//   = 5+1=> 6
//   = 4+2=> 6 (these leeds to sum of twin)

//twin sum remainds the beginning n the end always balance


/* The problem asks for the maximum twin sum in a linked list.
A twin pair is formed by pairing the first and last node, second and second-last, etc.

👉 Instead of using extra space to store values, we:

Find the middle of the list
Reverse the second half
Then compare pairs directly
🚀 Approach
Use two pointers (slow, fast) to find the middle of the linked list
Reverse the second half of the list
Traverse both halves simultaneously:
first half from head
second half from reversed middle
Compute the maximum sum of corresponding nodes
📊 Complexity
Time complexity: O(n)
(one pass to find middle + one pass to reverse + one pass to compute sum)

Space complexity: O(1)
(in-place reversal, no extra data structures)

*/