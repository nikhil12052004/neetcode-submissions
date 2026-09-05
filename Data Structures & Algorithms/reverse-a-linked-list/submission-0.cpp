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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        vector<int> arr;
        ListNode* it = head;
        while(it != NULL){
            arr.push_back(it->val);
            it = it->next;
        }
        int n = arr.size();
        ListNode* temp = new ListNode(arr[0]);
        for(int i = 1; i<n; i++){
            ListNode* curr = new ListNode(arr[i]);
            curr->next = temp;
            temp = curr; 
        }
        return temp;
    }
};
