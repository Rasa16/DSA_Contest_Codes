class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> map;
        vector<int> ans(k, 0);
        for(auto i = 0; i < logs.size(); i++)
        {
            map[logs[i][0]].insert(logs[i][1]);
        }
        
        for(auto i = map.begin(); i != map.end(); i++)
            ans[i->second.size() - 1]++;
        
        return ans;
    }
};