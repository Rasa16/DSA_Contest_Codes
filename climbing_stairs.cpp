//https://leetcode.com/problems/climbing-stairs/submissions/
//https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118824/offering/1382033

class Solution
{
    public:
    int mod = 1e9+7;
    //Function to count number of ways to reach the nth stair.
    int countWays(int nStairs)
    {
        // your code here
        long long dp[nStairs+1] = {0};
        int arr[2] = {1,2};
        dp[0] = 1;
        for(int i = 1; i<=nStairs; i++){
            for(int j = 0; j<2; j++){
                if(i >= arr[j]){
                    dp[i] += dp[i-arr[j]]%mod;
                }
            }
        }
        return dp[nStairs]%mod;
    }
};
