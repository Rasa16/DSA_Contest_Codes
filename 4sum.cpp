//https://leetcode.com/problems/4sum/submissions/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        
        if(n < 4) return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int rem = target - (nums[i] + nums[j]);
                int s = j+1;
                int e = n-1;
                
                while(s<e){
                    
                    int pair_sum = nums[s] + nums[e];
                    
                    if(pair_sum < rem) s++;
                    
                    else if(pair_sum > rem) e--;
                    
                    else{
                        vector<int> t(4,0);
                        t[0]=nums[i];
                        t[1]=nums[j];
                        t[2]=nums[s];
                        t[3]=nums[e];
                        ans.push_back(t);
                        
                        while(s<e && nums[s]==t[2]) s++;
                        while(s<e && nums[e]==t[3]) e--;
                    }
                }
                while(j+1 < n && nums[j+1] == nums[j]) ++j;
                
            }
                while(i+1 < n && nums[i+1] == nums[i]) ++i;
        }
        return ans;
    }
};
