//https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1


class Solution{
  public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    void dfs(Node* root, int count, int val, int &ans){
        if(root==NULL)
            return;
        if(root->data == val+1)
            count++;
        else
            count = 1;
        ans = max(ans, count);
        
        dfs(root->left, count, root->data, ans);
        dfs(root->right, count, root->data, ans);
    }
    int longestConsecutive(Node* root)
    {
         //Code here
         int ans = 1;
         int count = 0;
         
         dfs(root, count, INT_MIN, ans);
         
         if(ans == 1)
            return -1;
        return ans;
    }
};