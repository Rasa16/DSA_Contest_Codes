class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = nums[0];
        int i = 0;
        int ans = 0;
        int curr = 0;
        
        while(i<=maxJump){
            if(i == n-1)
                return ans;
            maxJump = max(maxJump, i+nums[i]);
            if(curr == i){
                ans++;
                curr = maxJump;
            }
            i++;
        }
        return ans;
    }
};