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
    int preind = 0;
    TreeNode* help(vector<int> in, vector<int> pre, unordered_map<int, int> mp, int instart, int inend){
        
        if(instart > inend)
            return NULL;
        int t = pre[preind++];
        TreeNode* tnode = new TreeNode(t);
        
        if(instart == inend)
            return tnode;
        int inind = mp[t];
        
        tnode->left = help(in, pre, mp, instart, inind-1);
        tnode->right = help(in, pre, mp, inind+1, inend);
        
        return tnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        if(inorder.size() ==1)
            return new TreeNode(inorder[0]);
        for(int i = 0; i<preorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return help(inorder, preorder, mp, 0, inorder.size()-1);
    }
};