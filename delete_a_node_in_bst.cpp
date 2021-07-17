//https://leetcode.com/problems/delete-node-in-a-bst/
//https://www.codingninjas.com/codestudio/problems/delete-node-in-bst_920381?leftPanelTab=0

/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
int predecessor(BinaryTreeNode<int>* root)
    {
        root = root->left;
        while(root->right != NULL)
            root = root->right;
        return root->data;
    }
    int sucessor(BinaryTreeNode<int>* root)
    {
        root = root->right;
        while(root->left != NULL)
            root = root->left;
        return root->data;
    }
BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
    // Write your code here.
    if(root == NULL)
        return NULL;
    if(root->data < key)
        root->right = deleteNode(root->right, key);
    else if(root->data > key)
        root->left = deleteNode(root->left, key);
    else{
        if(!root->left && !root->right)
            return NULL;
        else if(root->right){
            root->data = sucessor(root);
            root->right = deleteNode(root->right, root->data);
        }
        else{
            root->data = predecessor(root);
            root->left = deleteNode(root->left, root->data);
        }
    }
    return root;
}
