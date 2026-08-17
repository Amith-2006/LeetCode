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

        ListNode* prev = NULL;
        ListNode* curr = l1;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l1 = prev;

        prev = NULL;
        curr = l2;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l2 = prev;

        int carry = 0;
        ListNode dummy(0);
        curr = &dummy;

        while(l1 || l2 || carry) {
            int sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            carry = sum / 10;
        }

        prev = NULL;
        curr = dummy.next;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};