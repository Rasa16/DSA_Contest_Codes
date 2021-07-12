//https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?leftPanelTab=1

/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int, vector<int>> m;
    queue<int> l;
    queue<BinaryTreeNode<int> *> q;
    if(root == NULL)
        return {};
    int hd = 0;
    q.push(root);
    l.push(hd);
    BinaryTreeNode<int> *p;
    while(!q.empty()){
        p = q.front();
        hd = l.front();
        q.pop();
        l.pop();
        
        m[hd].push_back(p->data);
        if(p->left){
            q.push(p->left);
            l.push(hd-1);
        }
        if(p->right){
            q.push(p->right);
            l.push(hd+1);
        }
    }
    vector<int> res, t;
    for(auto i : m){
        t = i.second;
        res.push_back(t[t.size()-1]);
    }
    return res;
}
