//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/submissions/

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
    int mod = 1e9+7;
    long long totalSum=0, maxproduct=INT_MIN;

    void sum(TreeNode* root, long long &s){
        if(root){
            s += root->val;
            sum(root->left, s);
            sum(root->right, s);
        }
    }
    long long fp(TreeNode* root){
        if(!root) return 0;
        long long left = fp(root->left);
        long long right = fp(root->right);
        long long curSum = left+right+root->val;
        maxproduct = std::max(((totalSum-curSum)*curSum),maxproduct);
        return curSum;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        
        sum(root, totalSum);
        
        fp(root);
        
        return maxproduct%mod;
    }
};
