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
    ListNode* oddEvenList(ListNode* head) {
        // Create the odd linked list, and the even linked list
        // the odd will be the first, and then the pointer skips every two
        // the even will be the second, and then the pointer that odes not skip every two
        ListNode * oddHead = head;
        if(oddHead == nullptr){
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode * startOdd = oddHead;
        ListNode * startEven = evenHead;
        if(evenHead == nullptr){
            return head;
        }
    
        while(oddHead != nullptr && oddHead->next != nullptr){
            oddHead->next = (oddHead->next)->next;
            if(oddHead->next != nullptr){
                oddHead = oddHead->next;
            }
            evenHead->next = oddHead->next;
            evenHead = evenHead->next;
        }
        oddHead->next = startEven;
        return startOdd;
    }
};
