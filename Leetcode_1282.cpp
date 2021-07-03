//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> t;
        vector<vector<int>> res;
        
        for(int i=0;i<groupSizes.size();i++){
            t[groupSizes[i]].push_back(i);
            
            if(t[groupSizes[i]].size()==groupSizes[i]){
                res.push_back( t[groupSizes[i]]);
                t[groupSizes[i]].clear();
                
            }
        }
        return res;
    }
};
