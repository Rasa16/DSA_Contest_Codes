class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        
        if(sum & 1)
            return 0;
        int t = sum/2;
        
        bool dp[n+1][t+1];
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j<=t; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=t; j++){
                if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else{
                    if(dp[i-1][j])
                        dp[i][j] = 1;
                    else{
                        if(dp[i-1][j-nums[i-1]])
                            dp[i][j] = 1;
                        else
                            dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[n][t];
    }
};