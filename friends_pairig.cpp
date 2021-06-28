//https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
//https://www.youtube.com/watch?v=SHDu0Ufjyk8

class Solution
{
public:
    int mod = 1e9 + 7;
    int countFriendsPairings(int n) 
    { 
        // code here
        int dp[n+1];
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(long long int i = 3; i<=n; i++){
            dp[i] = ((dp[i-1])%mod+(i-1)%mod*(dp[i-2])%mod)%mod;
        }
        return dp[n];
    }
};    
