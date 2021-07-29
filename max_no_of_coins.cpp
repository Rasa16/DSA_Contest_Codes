//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/submissions/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        if(n <= 1)
            return 0;
         sort(piles.begin(), piles.end(), greater<int>());
        int it = n/3;
        int ans = 0;
        for(int i = 1; i<n-it; i = i+2)
            ans += piles[i];
        return ans;
    }
};
