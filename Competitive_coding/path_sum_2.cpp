//https://leetcode.com/problems/path-sum-ii/

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
    void fun(vector<vector<int>> &res, vector<int> &t, TreeNode* root, int k){
        if(root == NULL)
            return;
        if(!root->left && !root->right && root->val == k){
            t.push_back(root->val);
            res.push_back(t);
            t.pop_back();
            return;
        }
        t.push_back(root->val);
        fun(res, t, root->left, k-root->val);
        fun(res, t, root->right, k-root->val);
        t.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> t;
        fun(res,t,root, targetSum);
        return res;
    }
};
