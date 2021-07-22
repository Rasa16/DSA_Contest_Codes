//https://leetcode.com/problems/add-two-numbers/submissions/

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
    int length(ListNode* t){
        int len = 0;
        ListNode* p = t;
        while(p){
            len++;
            p = p->next;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        
        ListNode* p = l1;
        ListNode* q = l2;
        
        bool carry = 0;
        
        ListNode* head = NULL;
        ListNode* curr = NULL;
        
        while(p && q){
            int x = p->val + q->val;
            x = carry==1 ? x+1:x;
            carry = 0;
            if(x > 9){
                carry = 1;
                x = x%10;
            }
            
            ListNode* t = new ListNode(x);
            if(head == NULL){
                head = t;
                curr = t;
            }
            else{
                curr->next = t;
                curr = t;
            }
            p = p->next;
            q = q->next;
        }
        while(p != NULL){
            if(carry){
                int x = p->val+1;
                carry = 0;
                if(x > 9){
                    carry = 1;
                    x = x%10;
                }
                ListNode* t = new ListNode(x);
                curr->next = t;
                curr = t;
            }
            else{
                curr->next = p;
                break;
            }
            p = p->next;
        }
        while(q){
            if(carry){
                int x = q->val+1;
                carry = 0;
                if(x > 9){
                    carry = 1;
                    x = x%10;
                }
                ListNode* t = new ListNode(x);
                curr->next = t;
                curr = t;
            }
            else{
                curr->next = q;
                break;
            }
            q = q->next;
        }
        while(carry){
            ListNode* t = new ListNode(1);
            curr->next = t;
            carry = 0;
        }
        return head;
    }
};
