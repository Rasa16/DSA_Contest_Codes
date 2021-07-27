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
    int countNodes(TreeNode* root){
        if(root == NULL)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    TreeNode* find(TreeNode* root, int x){
        if(root == NULL)
            return NULL;
        if(root->val == x)
            return root;
        TreeNode* l = find(root->left, x);
        TreeNode* r = find(root->right, x);
        if(!l)
            return r;
        return l;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* first = find(root, x);
        if(first == NULL)
            return true;
        
        int first_left = countNodes(first->left);
        int first_right = countNodes(first->right);
        int first_parent = countNodes(root) - first_left - first_right - 1;
        
        int ans = max(first_left, max(first_right, first_parent));
        cout<<first_left<<" "<<first_right<<" "<<first_parent<<endl;
        if(ans > n-ans)
            return true;
        return false;
    }
};
