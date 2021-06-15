class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int inc = nums[0];
        int exc = 0;
        int t;
        
        for(int i = 1; i<n; i++){
            t = inc;
            inc = nums[i] + exc;
            exc = max(t, exc);
        }
        return max(inc, exc);
    }
};