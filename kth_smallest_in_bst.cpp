//https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/

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
    void inorder(TreeNode* root, int &n, int &ans, int K){
        if(!root || n >K)
            return;
        inorder(root->left, n, ans, K);
        n++;
        if(n == K){
            ans = root->val;
            return;
        }
        inorder(root->right, n, ans, K);
    }
    int kthSmallest(TreeNode* root, int k) {
        int n = 0, ans = -1;
        inorder(root, n, ans, k);
        if(n < k)
            return -1;
        return ans;
    }
};
