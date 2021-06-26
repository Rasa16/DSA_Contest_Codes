//https://leetcode.com/problems/minimum-size-subarray-sum/submissions/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        while(j < n){
            while(sum < target && j<n){
                sum += nums[j];
                j++;
            }
            while(sum>=target && i<n){
                ans = min(ans, (j-i+1));
                sum -= nums[i];
                i++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans-1;
    }
};
