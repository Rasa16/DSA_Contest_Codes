//https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int i = 2;
        int two_p = 1, three_p = 1, five_p = 1;
        while(i <= n){
            int two = dp[two_p]*2;
            int three = dp[three_p]*3;
            int five = dp[five_p] * 5;
            
            dp[i] = min(two, min(three, five));
            
            if(dp[i] == two)
                two_p++;
            if(dp[i] == three)
                three_p++;
            if(dp[i] == five)
                five_p++;
            i++;
            
        }
        return dp[n];
    }
};
