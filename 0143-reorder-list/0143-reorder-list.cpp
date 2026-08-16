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
    void reorderList(ListNode* head) {
        if(!head||head->next==NULL) return;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = NULL;

        ListNode *prev = NULL;
        ListNode *curr = list2;

        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        list2 = prev;

        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        
        while(temp2){
            ListNode *next1 = temp1->next;
            ListNode *next2 = temp2->next;

            temp1->next = temp2;
            temp2->next = next1;

            temp1 = next1;
            temp2 = next2; 
        }
    }
};