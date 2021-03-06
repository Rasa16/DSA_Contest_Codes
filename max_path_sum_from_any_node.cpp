class Solution {
  public:
    //Function to return maximum path sum from any node in a tree
    int solve(Node* root, int &res){
        if(root == nullptr)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        
        int temp = max((max(l, r) + root->data), root->data);
        int ans = max(temp, l+r+root->data);
        
        res = max(res, ans);
        
        return temp;
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int res = INT_MIN;
        solve(root, res);
        return res;
        
    }
};