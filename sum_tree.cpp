//https://www.codingninjas.com/codestudio/problems/sum-tree_10373?leftPanelTab=0

/*************************************************************
 
    Following is the Binary Tree node structure

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
void sum(BinaryTreeNode<int> * root){
    if(root == NULL)
        return;
    if(root->left && root->right)
        root->data = root->left->data + root->right->data;
    else{
        if(root->left)
            root->data = root->left->data;
        else if(root->right)
            root->data = root->right->data;
        else
            root->data = 0;
    }
    sum(root->left);
    sum(root->right);
}
void preorder(BinaryTreeNode<int> *root, vector<int> &v){
    if(root){
        v.push_back(root->data);
        preorder(root->left, v);
        preorder(root->right, v);
    }
}
vector<int> sumTree(BinaryTreeNode<int> *root)
{
    //Write your code here
    sum(root);
    vector<int> v;
    preorder(root, v);
    return v;
}
