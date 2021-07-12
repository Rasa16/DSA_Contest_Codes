//https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?leftPanelTab=1
//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    queue<TreeNode<int> *> q;
    queue<int> l;
    int hd = 0;
    map<int, vector<int>> m;
    if(root != NULL){
        q.push(root);
        hd = 0;
        l.push(hd);
        m[hd].push_back(root->val);
    }
    TreeNode<int> *p;
    int t;
    while(!q.empty()){
        p = q.front();
        t = l.front();
        q.pop();
        l.pop();
        if(p->left){
            q.push(p->left);
            l.push(t-1);
            m[t-1].push_back(p->left->val);
        }
        if(p->right){
            q.push(p->right);
            l.push(t+1);
            m[t+1].push_back(p->right->val);
        }
    }
    vector<int> res;
    for (auto it : m){
        res.push_back(it.second[0]);
    }
    return res;
}
