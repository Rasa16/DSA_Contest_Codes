//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[W+1];
        
        dp[0] = 0;
        
        for(int i = 1; i<=W; i++){
            int m = 0;
            for(int j = 0; j<N; j++){
                if(wt[j] <= i){
                    int rbc = i - wt[j];
                    int rbv = dp[rbc];
                    int tbv = rbv + val[j];
                    
                    m = max(m, tbv);
                }
            }
            dp[i] = m;
        }
        return dp[W];
    }
};
