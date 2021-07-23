//https://leetcode.com/problems/next-greater-node-in-linked-list/submissions/

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
    void nge(ListNode* node, stack<int> &st, vector<int> &v){
        if(node == NULL)
            return;
        nge(node->next, st, v);
        
        if(st.empty()){
            v.push_back(0);
            st.push(node->val);
        }
        else{
            while(!st.empty() && st.top() <= node->val)
                st.pop();
            if(st.empty()){
                v.push_back(0);
                st.push(node->val);
            }
            else{
                v.push_back(st.top());
                st.push(node->val);
            }
        }
    }
    vector<int> nextLargerNodes(ListNode* head) {
        if(head == NULL)
            return {};
        if(head->next == NULL)
            return {0};
        vector<int> v;
        stack<int> st;
        nge(head, st, v);
        reverse(v.begin(), v.end());
        return v;
    }
};
