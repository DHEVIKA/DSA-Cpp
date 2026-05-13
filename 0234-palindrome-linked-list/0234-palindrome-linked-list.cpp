class Solution {
public:

    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // find middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* p1 = head;
        ListNode* p2 = reverseLinkedList(slow);

        // compare both halves
        while (p2 != nullptr) {

            if (p1->val != p2->val) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }

    ListNode* reverseLinkedList(ListNode* curr) {

        ListNode* prev = nullptr;

        while (curr != nullptr) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;
        }

        return prev;
    }
};

/* Example:
check if a linkedlist is a palindrome by reversing its \2nd half & comparing it with 1st half
1 -> 2 -> 2 -> 1
Step 1: Find middle

slow reaches second 2

Step 2: Reverse second half
2 -> 1
becomes
1 -> 2
Step 3: Compare
1 == 1
2 == 2

Return true.

Time Complexity
O(n)
Space Complexity
O(1)

because reversal is done in-place. */