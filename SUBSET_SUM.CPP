//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here
        bool dp[N+1][sum+1];
        
        for(int i = 0; i<=N; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j<=sum; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=sum; j++){
                if(j < arr[i-1])
                    dp[i][j] = dp[i-1][j];
                else{
                    if(dp[i-1][j])
                        dp[i][j] = 1;
                    else{
                        if(dp[i-1][j-arr[i-1]])
                            dp[i][j] = 1;
                        else
                            dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[N][sum];
    }
};
