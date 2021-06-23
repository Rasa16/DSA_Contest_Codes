//https://practice.geeksforgeeks.org/problems/coin-change2448/1#

class Solution
{
  public:
    long long int count( int s[], int m, int n )
    {
       
        //code here.
        long long dp[n+1];
        for(int i = 0; i<=n; i++)
            dp[i] = 0;
        dp[0] = 1;
        
        for(int i = 0; i<m; i++){
            for(int j = s[i]; j<=n; j++){
                dp[j] += dp[j-s[i]];
            }
        }
        return dp[n];
    }
};