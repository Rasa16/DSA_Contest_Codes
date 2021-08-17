//https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode* dummy = new ListNode(0);
        
        dummy->next = head;
        
        ListNode* p = dummy;
        
        while(p && p->next){
            if(p->next->val == val){
                ListNode* temp = p->next;
                p->next = temp->next;
                delete(temp);
            }else
                p = p->next;
        }
        return dummy->next;
    }
};
