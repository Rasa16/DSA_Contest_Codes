//https://www.codingninjas.com/codestudio/problems/zig-zag-traversal_1062662?leftPanelTab=0
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if(root == NULL)
        return {};
    vector<vector<int>> v;
    queue<BinaryTreeNode<int>*> q;
    vector<int> t;
    
    q.push(root);
    BinaryTreeNode<int>* p;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            p = q.front();
            q.pop();
            t.push_back(p->data);
            
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
        v.push_back(t);
        t.clear();
    }
    int s = v.size();
    int i = 1;
    vector<int> res;
    while(i <= s){
        if(i & 1){
            for(int j : v[i-1])
                res.push_back(j);
        }
        else{
            for(int j = v[i-1].size()-1; j>=0; j--){
                res.push_back(v[i-1][j]);
            }
        }
        i++;
    }
    return res;
}
