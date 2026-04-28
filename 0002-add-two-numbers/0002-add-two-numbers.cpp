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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* output = new ListNode();  

        ListNode* head = output;

        ListNode* p1 = l1;

        ListNode* p2 = l2;

        int carry = 0;

        while (p1 != nullptr || p2 != nullptr || carry != 0) {

            int curSum = (p1 != nullptr ? p1->val : 0) +

                        (p2 != nullptr ? p2->val : 0) +

                        carry;

            int newNodeVal = curSum % 10;

            output->next = new ListNode(newNodeVal);

            output = output->next;

            carry = curSum / 10;

            p1 = (p1 != nullptr ? p1->next : nullptr);

            p2 = (p2 != nullptr ? p2->next : nullptr);

        }

        return head->next;

    }
};


/**

input: 
l1 = 2 -> 4 -> 3 -> NULL
l2 = 4 -> 6 -> 4 -> NULL

output: 
6 -> 0 -> 8 -> NULL

p1 = NULL
p2 = NULL

         head                 |  
output = [] -> [6] ->[0] -> [8]
carry = 0

curSum = (p1 != null ? p1.val : 0) + (p2 != null ? p2.val : 0) + carry 
        = 2 + 4 + 0 => 6
        = 4 + 6 + 0 => 10
        = 3 + 4 + 1 => 8

newNodeVal = curSum % 10
           = 6 % 10 = 6
           = 10 % 10 = 0
           = 8 % 10 = 8

newNode = new Node(newNodeVal)

output.next = newNode
output = output.next

p1 = (p1 != null ? p1.next : null)
p2 = (p2 != null ? p2.next : null)

curCarry = curSum / 10
      = 6 / 10 => 0
      = 10 / 10 => 1
      = 8 / 10 => 0

carry = curCarry




l1 = [9, 9, 9]
l2 = [9, 9]

Expected: [8, 9, 0, 1]


p1 = null
p2 = null

carry = 0

output: [] -> 8 -> 9 -> 0 -> 1

cur = (0 + 0 + 1) => 1

node = (cur % 10) 
	 = 18 % 10 -> 8
	 = 19 % 10 -> 9
	 = 10 % 10 -> 0
	 = 1 % 10 -> 1

carry = cur / 10
	 = 18 / 10 => 1
	 = 19 / 10 => 1
	 = 10 / 10 => 1
	 = 1 / 10 => 0



*/