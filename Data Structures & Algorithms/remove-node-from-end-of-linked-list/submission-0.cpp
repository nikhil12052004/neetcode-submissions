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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* curr = head;
        ListNode* dummy = head;
        for(int i = 0; i<n; i++){
            dummy = dummy->next;
        }
        if(dummy == NULL) {
            ListNode* newHead = head->next;
            delete head; // Memory clean
            return newHead;
        }
        while(dummy->next != NULL){
            dummy = dummy->next;
            curr = curr->next;
        }
        ListNode* del = curr->next;
        curr->next = curr->next->next;
        delete del;
        return head;
    }
};
