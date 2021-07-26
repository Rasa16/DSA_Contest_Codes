//https://leetcode.com/problems/count-good-nodes-in-binary-tree/solution/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class max_pair{
    public:
    TreeNode* p = NULL;
    int msf = INT_MIN;
};
class Solution {
public:
    int goodNodes(TreeNode* root) {
        stack<max_pair> st;
        
        st.push({root, INT_MIN});
        
        int goodNodes = 0;
        
        while(!st.empty()){
            max_pair t = st.top();
            st.pop();
            
            if(t.p->val >= t.msf){
                goodNodes++;
            }
            
            if(t.p->left)
                st.push({t.p->left, max(t.p->val, t.msf)});
            if(t.p->right)
                st.push({t.p->right, max(t.p->val, t.msf)});
        }
        return goodNodes;
    }
};
