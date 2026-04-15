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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return nullptr;
        } 
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        fastPointer = (fastPointer->next)->next;
        while(fastPointer != nullptr && fastPointer->next != nullptr){
            fastPointer = (fastPointer->next)->next;
            slowPointer = slowPointer->next; // now at halfway point
        }
        
        slowPointer->next = (slowPointer->next)->next;
        return head;
    }
};
