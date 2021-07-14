//https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1

int sum(Node* root, int &count, int X){
    if(root == NULL)
        return 0;
    int curr = root->data + sum(root->left, count, X) + sum(root->right, count, X);
    if(curr == X)
        count++;
    return curr;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count = 0;
	sum(root, count, X);
	return count;
}
