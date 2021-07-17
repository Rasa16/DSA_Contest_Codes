//https://www.codingninjas.com/codestudio/problems/check-if-a-binary-tree-is-bst_5975?leftPanelTab=0

#include<bits/stdc++.h>
bool bstutil(BinaryTreeNode<int> *root, int low, int high){
    if(root == NULL)
        return 1;
    if(root->data < low || root->data > high)
        return 0;
    return bstutil(root->left, low, root->data-1) && bstutil(root->right, root->data+1, high);
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    return bstutil(root, INT_MIN, INT_MAX);
}
