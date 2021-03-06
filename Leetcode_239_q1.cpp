class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                int t = abs(i-start);
                ans = min(ans, t);
            }
        }
        return ans;
    }
};