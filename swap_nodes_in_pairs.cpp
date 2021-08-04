//https://leetcode.com/problems/swap-nodes-in-pairs/

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
    int length(ListNode* head){
        if(head == NULL)
            return 0;
        return length(head->next)+1;
    }
    ListNode* swapPairs(ListNode* head) {
        int len = length(head);
        if(len == 0 || len == 1)
            return head;
        int num = len/2;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = prev;
        ListNode* nex;
        
        while(num--){
            prev = curr;
            curr = prev->next;
            nex = curr->next;
            prev->next = nex;
            curr->next = nex->next;
            nex->next = curr;
        }
        return dummy->next;
    }
};
