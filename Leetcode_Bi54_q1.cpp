class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> vis(51, 0);
        
        for(auto v:ranges){
            for(int i = v[0]; i<=v[v.size()-1]; i++){
                vis[i] = true;
            }
        }
        for(int i = left; i<=right; i++){
            if(!vis[i])
                return false;
        }
        return true;
    }
};