//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380979?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1#
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
************************************************************/
#include<algorithm>
vector<vector<int>> level(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    vector<vector<int>> res;
    vector<int> t;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            BinaryTreeNode<int> *p = q.front();
            q.pop();
            
            t.push_back(p->data);
            if(p->left)
                q.push(p->left);
            if(p->right)
              q.push(p->right);
        }
        res.push_back(t);
        t.clear();
    }
    return res;
}
vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
	// Write Your Code Here.
    if(root == NULL)
        return {};
    vector<vector<int>> v = level(root);
    vector<int> res;
    for(int i = 0; i<v.size(); i++){
        if((i+1) & 1){
            for(auto j : v[i])
                res.push_back(j);
        }
        else{
            reverse(v[i].begin(), v[i].end());
           for(auto j : v[i])
               res.push_back(j);
        }
    }
    return res;
}
