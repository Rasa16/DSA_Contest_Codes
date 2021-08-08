//https://leetcode.com/problems/permutations-ii/

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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> vis(n, 0);
        
        rec(res, temp, vis, nums);
        
        for(auto v : res)
            s.insert(v);
        res.clear();
        
        for(auto v : s)
            res.push_back(v);
        
        return res;
    }
};
