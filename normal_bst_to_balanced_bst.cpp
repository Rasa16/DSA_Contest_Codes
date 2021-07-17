//https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0
//https://leetcode.com/problems/balance-a-binary-search-tree/submissions/
//https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1#

/*************************************************************
    Following is the Binary Serach Tree node structure

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
BinaryTreeNode<int> *buildtree(vector<int> v, int s, int e){
    if(s > e)
        return NULL;
    int mid = (s+e)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (v[mid]);
    
    root->left = buildtree(v, s, mid-1);
    root->right = buildtree(v, mid+1, e);
    return root;
}

void inorder(BinaryTreeNode<int> *root, vector<int> &v){
    if(root){
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}
BinaryTreeNode<int>* balancedBst(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> v;
    inorder(root, v);
    
    int n = v.size();
    return buildtree(v, 0, n-1);
}
