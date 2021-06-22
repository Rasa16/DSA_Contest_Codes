class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[x+1][y+1];
        
        for(int i = 0; i<=x; i++){
            dp[i][y] = 0;
        }
        for(int j = 0; j<=y; j++){
            dp[x][j] = 0;
        }
        
        for(int i = x-1; i>=0; i--){
            for(int j = y-1; j>=0; j--){
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};