class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) /// edge case if heead is facing null jus return null
            return nullptr;

        if (head->next == nullptr) // if theres is a single node just we cant able to reverse the linkedlist so retuyrn head
            return head;

        ListNode* preNode = nullptr; 
        ListNode* currNode = head;

        while (currNode != nullptr) {
            ListNode* nextNode = currNode->next;
            currNode->next = preNode;
            preNode = currNode;
            currNode = nextNode;
        }

        return preNode;
        return head;
    }
};

/* no need to use use any data structure or any kind of extra space 
    1. Inplace manipulations
       needed Nodes:
           1. previous
           2. current
           3. current Next 
    2. Make the previous node as null 
    3. make the current node as head
    4. looop stats
       1->2->3->4->5->NULL
       as
      NULL <-5<-4<-3<-2<-1 -> HEAD

ListNode* nextNode = currNode->next;
            currNode->next = preNode;
            preNode = currNode;
            currNode = nextNode;

*/