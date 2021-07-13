//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380978?leftPanelTab=0

/**********************************************************
    Following is the Binary Tree Node class structure.

    template <typename T>
    class BinaryTreeNode {
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

***********************************************************/
#include<algorithm>
vector<vector<int>> diagonal(BinaryTreeNode<int>* root1){
    queue<BinaryTreeNode<int>*> q;
    q.push(root1);
    vector<vector<int>> res;
    vector<int> t;
    BinaryTreeNode<int>* p;
    
    while(!q.empty()){
        int size = q.size();
        while(size--){
            p = q.front();
            q.pop();
            while(p){
                t.push_back(p->data);
                if(p->left)
                    q.push(p->left);
                p = p->right;
            }
        }
        res.push_back(t);
        t.clear();
    }
    return res;
}
bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.
    if(!root1 && !root2)
        return 1;
    if(!root1 && !root2)
        return 0;
    vector<vector<int>> v1, v2;
    v1 = diagonal(root1);
    v2 = diagonal(root2);
    
    if(v1.size() != v2.size())
        return 0;
    for(int i = 0; i<v1.size(); i++){
        if(v1[i].size() != v2[i].size())
            return 0;
        sort(v1[i].begin(), v1[i].end());
        sort(v2[i].begin(), v2[i].end());
        if(v1[i] != v2[i])
            return 0;
    }
    return 1;
}
