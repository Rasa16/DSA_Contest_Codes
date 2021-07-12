//https://www.codingninjas.com/codestudio/problems/convert-binary-tree-to-mirror-tree_873140?topList=top-trees-interview-questions&leftPanelTab=1
//https://leetcode.com/problems/invert-binary-tree/submissions/
//https://practice.geeksforgeeks.org/problems/mirror-tree/1#

void mirrorTree(BinaryTreeNode<int> *root) {
    // Write your code here.
    if(root == NULL)
        return;
    //swap(root->left, root->right);
    BinaryTreeNode<int> *t = root->left;
    root->left = root->right;
    root->right = t;
    mirrorTree(root->left);
    mirrorTree(root->right);
}
