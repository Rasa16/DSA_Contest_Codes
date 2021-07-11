//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380976?leftPanelTab=0

#include<bits/stdc++.h>

/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void lsub(TreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    if(root->left){
        v.push_back(root->data);
        lsub(root->left, v);
    }
    else if(root->right){
        v.push_back(root->data);
        lsub(root->right, v);
    }
}

void rsub(TreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    if(root->right){
        v.push_back(root->data);
        rsub(root->right, v);
    }
    else if(root->left){
        v.push_back(root->data);
        rsub(root->left, v);
    }
}

void leafsub(TreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    if(!root->left && !root->right)
        v.push_back(root->data);
    leafsub(root->left, v);
    leafsub(root->right, v);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> l, r, leaf;
    if(!root->left && !root->right)
        return {root->data};
   	if(root->left)
    	lsub(root->left, l);
    leafsub(root, leaf);
   	if(root->right)
    	rsub(root->right, r);
    
    l.insert(l.end(), leaf.begin(), leaf.end());
    reverse(r.begin(), r.end());
    l.insert(l.end(), r.begin(), r.end());
    l.insert(l.begin(), root->data);
    
    return l;
}
