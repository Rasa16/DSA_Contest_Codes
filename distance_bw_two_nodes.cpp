//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1381014?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool nodeToRoot(TreeNode<int> *root, int node1, vector<int> &v){
    if(root == NULL)
        return false;
    if(root->val == node1){
        v.push_back(root->val);
        return true;
    }
    if(nodeToRoot(root->left, node1, v)){
        v.push_back(root->val);
        return true;
    }
    if(nodeToRoot(root->right, node1, v)){
        v.push_back(root->val);
        return true;
    }
    return false;  
}
int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2)
{
    // Write your code here.
    vector<int> v1, v2;
    bool n1 = nodeToRoot(root, node1, v1);
    bool n2 = nodeToRoot(root, node2, v2);
    if(!n1 || !n2)
        return -1;
    int i = v1.size()-1, j = v2.size() - 1;
    while(i >=0 && j >= 0 && v1[i] == v2[j]){
        i--;
        j--;
    }
    i++;
    j++;
    return i+j;
}
