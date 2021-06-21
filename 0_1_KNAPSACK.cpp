int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	// Write your code here
    // Your code here
       int dp[n+1][W+1];
       
       for(int i = 0; i<W+1; i++){
           dp[0][i] = 0;
       }
       for(int i = 0; i<n+1; i++){
           dp[i][0] = 0;
       }
       
       for(int i = 1; i<n+1; i++){
           for(int j = 1; j < W+1; j++){
               dp[i][j] = dp[i-1][j];
               if(j >= wt[i-1]){
                   int rcap = j - wt[i-1];
                   if(dp[i][j] < dp[i-1][rcap] + val[i-1]){
                       dp[i][j] = dp[i-1][rcap] + val[i-1];
                   }
               }
           }
       }
       return dp[n][W];
}