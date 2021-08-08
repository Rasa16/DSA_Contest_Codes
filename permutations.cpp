//https://leetcode.com/problems/permutations/

class Solution {
public:
    
    void rec(vector<vector<int>> &res, vector<int> &temp, vector<bool> &vis, vector<int> nums){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                temp.push_back(nums[i]);
                rec(res, temp, vis, nums);
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> vis(n, 0);
        
        rec(res, temp, vis, nums);
        
        return res;
    }
};
