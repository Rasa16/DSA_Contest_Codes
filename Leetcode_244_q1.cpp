class Solution {
public:
    static bool mycmp(pair<int, int> p1, pair<int, int> p2){
        return p1.first < p2.first;
    }
    int reductionOperations(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0 ; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<pair<int, int>> v;
        pair<int, int> p;
        for(auto x:m){
            p = {x.first, x.second};
            v.push_back(p);
        }
        sort(v.begin(), v.end(), mycmp);
        
        if(v.size() == 1)
            return 0;
        int ans = 0;
        for(int i = v.size()-1; i>=1; i--){
            p = v[i];
            ans += p.second;
            v[i-1].second += p.second;
        }
        return ans;
    }
};