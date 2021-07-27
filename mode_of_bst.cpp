//https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/

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
class Solution {
public:
    void inorder(TreeNode* root, unordered_map<int, int> &m, int &omax){
        if(root){
            inorder(root->left, m, omax);
            m[root->val]++;
            if(m[root->val] > omax)
                omax = m[root->val];
            inorder(root->right, m, omax);
        }
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        int omax = INT_MIN;
        inorder(root, m, omax);
        
        vector<int> res;
        for(auto v : m){
            if(v.second == omax)
                res.push_back(v.first);
        }
        return res;
    }
};
