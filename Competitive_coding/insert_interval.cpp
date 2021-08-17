//https://leetcode.com/problems/insert-interval/

class Solution {
public:
    static bool mycmp(vector<int> v1, vector<int> v2){
        return v1[0]<v2[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        
        sort(intervals.begin(), intervals.end(), mycmp);
        for(auto v : intervals){
            if(res.empty())
                res.push_back(v);
            else{
                if(res[res.size()-1][1] >= v[0]){
                    res[res.size()-1][1] = max(res[res.size()-1][1], v[1]);
                }else
                    res.push_back(v);
            }
        }
        return res;
    }
};
