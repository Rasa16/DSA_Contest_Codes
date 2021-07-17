//https://www.codingninjas.com/codestudio/problems/populate-inorder-successor-of-all-nodes-of-a-binary-tree_1118625?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#

/*struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node* pre = NULL;
    void populateNext(Node *root)
    {
        //code here
        if(root == NULL)
            return;
        populateNext(root->left);
        if(pre)
            pre->next = root;
        pre = root;
        populateNext(root->right);
        
    }
};
