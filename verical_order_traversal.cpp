//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/
//https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533?leftPanelTab=1
//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#

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
    static bool comparator(const pair<int,int> &p1,const pair<int,int> &p2)
    {
        if(p1.second==p2.second)
            return p1.first<=p2.first;
        else if(p1.second<p2.second)
            return true;
        else
            return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        int level;
        map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int hd = q.front().second.first;
            level = q.front().second.second;
            q.pop();
            mp[hd].push_back({node->val,level});
            if(node->left)
                q.push({node->left,{hd-1,level+1}});
            if(node->right)
                q.push({node->right,{hd+1,level+1}});
        }
        for(auto it:mp)
        {
            sort(it.second.begin(),it.second.end(),comparator);
            vector<int> v;
            for(auto ele:it.second)
                v.push_back(ele.first);
            ans.push_back(v);
        }
        return ans;
    }
};
