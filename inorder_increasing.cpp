//https://leetcode.com/problems/increasing-order-search-tree/

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
    void inorder(TreeNode* root, vector<int> &v){
        if(root){
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        
        TreeNode* r = NULL;
        TreeNode* t = NULL;
        for(int i = 0; i<in.size(); i++){
            if(r == NULL){
                TreeNode* p = new TreeNode(in[i]);
                r = p;
                r->left = NULL;
                t = r;
            }
            else{
                TreeNode* p = new TreeNode(in[i]);
                t->right = p;
                p->left = NULL;
                t = t->right;
            }
        }
        return r;
    }
};
