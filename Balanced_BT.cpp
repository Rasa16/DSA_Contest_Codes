//https://www.codingninjas.com/codestudio/problems/is-height-balanced-binary-tree_975497?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
//https://leetcode.com/problems/balanced-binary-tree/

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
    int height(TreeNode* root){
    int x = 0, y = 0;
    if(root == NULL)
        return 0;
    x = height(root->left);
    y = height(root->right);
    
    if(x>y)
        return x+1;
    else
        return y+1;
}
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return 1;
        int x = height(root->left);
        int y = height(root->right);

        if(abs(x-y) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return 1;
        else
            return 0;
    }
};
