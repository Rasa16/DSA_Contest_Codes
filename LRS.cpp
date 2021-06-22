class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    int dp[n+1][n+1];
		    
		    for(int i = 0; i<=n; i++){
		        dp[i][n] = 0;
		    }
		    for(int j = 0; j<n; j++){
		        dp[n][j] = 0;
		    }
		    
		    for(int i = n-1; i>=0; i--){
		        for(int j = n-1; j>=0; j--){
		            if(str[i] == str[j]){
		                if(i == j)
		                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		                else
		                    dp[i][j] = dp[i+1][j+1] + 1;
		            }
		            else
		                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		        }
		    }
		    return dp[0][0];
		}

};