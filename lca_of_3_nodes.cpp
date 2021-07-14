//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1381011?leftPanelTab=0

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
bool nodeToRoot(BinaryTreeNode<int>*root, int node1, vector<int> &v){
    if(root == NULL)
        return false;
    if(root->data == node1){
        v.push_back(root->data);
        return true;
    }
    if(nodeToRoot(root->left, node1, v)){
        v.push_back(root->data);
        return true;
    }
    if(nodeToRoot(root->right, node1, v)){
        v.push_back(root->data);
        return true;
    }
    return false;  
}
BinaryTreeNode<int>* find(BinaryTreeNode<int>* root, int data){
    if(root == NULL)
        return NULL;
    if(root->data == data)
        return root;
    BinaryTreeNode<int>* p = find(root->left, data);
    if(p == NULL)
    	find(root->right, data);
    //return NULL;
}
BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    // Write your code here.
    vector<int> v1, v2,v3;
    bool  n1 = nodeToRoot(root, node1, v1);
    bool n2 = nodeToRoot(root, node2, v2);
    bool  n3 = nodeToRoot(root, node3, v3);
    
    if(!n1 || !n2 || !n3)
        return NULL;
    int i = v1.size()-1, j = v2.size()-1, k = v3.size()-1;
    while(i >= 0 && j >=0 && k >= 0 && v1[i] == v2[j] && v2[j] == v3[k]){
        i--;
        j--;
        k--;
    }
    i++;
    j++;
    k++;
    int data = v1[i];
    return find(root, data);
}
