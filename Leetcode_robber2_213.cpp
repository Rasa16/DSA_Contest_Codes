class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        int inc = nums[0];
        int exc = 0;
        int t;
        
        for(int i = 1; i<n-1; i++){
            t = inc;
            inc = nums[i]+exc;
            exc = max(t, exc);
        }
        int ans1 = max(inc, exc);
        
        inc = nums[1];
        exc = 0;
        for(int i = 2; i<n; i++){
            t = inc;
            inc = nums[i]+exc;
            exc = max(t, exc);
        }
        int ans2 = max(inc, exc);
        
        return max(ans1, ans2);
    }
};