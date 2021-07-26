//https://leetcode.com/problems/house-robber-iii/submissions/

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

class house_pair{
    public:
    int with = 0;
    int without = 0;
};
class Solution {
public:
    house_pair rec(TreeNode* root){
        house_pair ans;
        if(root==nullptr){
            return ans;
        }
        house_pair l=rec(root->left);
        house_pair r=rec(root->right);
        ans.with=root->val+l.without+r.without;
        ans.without=max(l.with,l.without)+max(r.with,r.without);
        return ans;
    }
    int rob(TreeNode* root) {
        house_pair ans=rec(root);
        return max(ans.with,ans.without);
    }
};
