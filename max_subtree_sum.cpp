//https://www.codingninjas.com/codestudio/problems/maximum-subtree-sum_1082330?leftPanelTab=0

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
long long sum(BinaryTreeNode<int> *root, long long &msum){
    if(root == NULL)
        return 0;
    long long curr = root->data + sum(root->left, msum) + sum(root->right, msum);
    
    msum = max(msum, curr);
    return curr;
}
long long maxSubtreeSum(BinaryTreeNode<int> *root){
	// Write your code here.
    if(root == NULL)
        return 0;
    long long ans = INT_MIN;
    sum(root, ans);
    return ans;
}
