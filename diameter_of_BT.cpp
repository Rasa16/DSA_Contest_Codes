//https://www.codingninjas.com/codestudio/problems/diameter-of-the-binary-tree_920552?topList=top-trees-interview-questions&leftPanelTab=1
//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
//https://leetcode.com/problems/diameter-of-binary-tree/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
struct dia{
    int h;
    int d;
};
struct dia diameter1(TreeNode<int> *root){
    if(root == NULL){
        dia bp;
        bp.h = -1;
        bp.d = 0;
        return bp;
    }
    dia lp = diameter1(root->left);
    dia rp = diameter1(root->right);
    
    dia mp;
    mp.h = max(lp.h, rp.h) + 1;
    
    int f = lp.h + rp.h + 2;
    mp.d = max(f, max(lp.d, rp.d));
    
    return mp;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    dia mp = diameter1(root);
    return mp.d;
}
