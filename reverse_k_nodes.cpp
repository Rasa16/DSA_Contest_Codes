//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy;
        ListNode* temp = dummy;
        int c = 0;
        while(head){
            head = head->next;
            c++;
        }
        
        while(c >= k){
            curr = prev->next;
            temp = curr->next;
            for(int i = 1; i<k; i++){
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
                temp = curr->next;
            }
            prev = curr;
            c-=k;
        }
        return dummy->next;
    }
};
