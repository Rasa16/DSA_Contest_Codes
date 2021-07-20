//https://leetcode.com/problems/destination-city/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> out;
        string ans = "";
        for(int i = 0; i < paths.size(); i++){
            out[paths[i][0]]++;
            if(out.find(paths[i][1]) == out.end())
                out[paths[i][1]] = 0;
        }
        
        for(auto i : out){
            if(i.second == 0){
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};
