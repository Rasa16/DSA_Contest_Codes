//https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        int width = 0;
        
        while(!q.empty()){
            int size = q.size();
            int si = q.front().second;
            int ei = q.back().second;
            
            width = max(width, ei-si+1);
            
            while(size--){
                TreeNode* p = q.front().first;
                int index = q.front().second;
                
                q.pop();
                
                index = index - si;
                
                if(p->left){
                    q.push({p->left, 2*index+1});
                }
                if(p->right){
                    q.push({p->right, 2*index+2});
                }
            }
        }
        return width;
    }
};
