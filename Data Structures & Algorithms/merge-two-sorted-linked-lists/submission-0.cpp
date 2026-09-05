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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        vector<int> arr;
        while(list1 != NULL){
            arr.push_back(list1->val);
            list1 = list1->next;
        }
        while(list2 != NULL){
            arr.push_back(list2->val);
            list2 = list2->next;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        ListNode* newHead = new ListNode(arr[0]);
        ListNode* curr = newHead;
        for(int i = 1; i<n; i++){
            ListNode* temp = new ListNode(arr[i]);
            curr->next = temp;
            curr = curr->next;
        }
        return newHead;
    }
};
