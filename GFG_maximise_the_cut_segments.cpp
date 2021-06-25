https://practice.geeksforgeeks.org/problems/cutted-segments1642/0/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&difficulty[]=0&page=1&query=category[]Dynamic%20Programmingdifficulty[]0page1category[]Dynamic%20Programming#

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n+1];
        
        dp[0] = 0;
        
        for(int i = 1; i<=n; i++){
            dp[i] = -1;
            
            if(i-x >= 0)
                dp[i] = max(dp[i], dp[i-x]);
            if(i-y >= 0)
                dp[i] = max(dp[i], dp[i-y]);
            if(i-z >= 0)
                dp[i] = max(dp[i], dp[i-z]);
            if(dp[i] != -1)
                dp[i]++;
        }
        return max(dp[n], 0);
    }
};