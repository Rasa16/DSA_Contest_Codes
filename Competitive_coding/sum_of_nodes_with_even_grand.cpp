//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    void grand(TreeNode* root, int &ans, int parent, int g){
        if(root){
            if(g%2 == 0)
                ans += root->val;
            g = parent;
            parent = root->val;
            
            grand(root->left, ans, parent, g);
            grand(root->right, ans, parent, g);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        int parent = 1, g = 1;
        int ans = 0;
        
        grand(root, ans, parent, g);
        
        return ans;
    }
};
