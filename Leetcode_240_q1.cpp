class Solution {
public:
    static bool mycmp(pair<int, bool> a, pair<int, bool> b){
        if(a.first == b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
    int maximumPopulation(vector<vector<int>>& logs) {
        
        
         int n = logs.size();
        
        vector<pair<int, bool>> v;
        for(int i = 0; i<n; i++){
            pair<int, bool> p1 = {logs[i][0], 1};
            v.push_back(p1);
            p1 = {logs[i][1], 0};
            v.push_back(p1);
        }
        sort(v.begin(), v.end(), mycmp);
        
        int c = 0;
        int year = 0;
        int m = 0;
        
        for(int i = 0; i<2*n; i++){
            pair<int, bool> p = v[i];
            if(p.second == 1){
                c++;
                if(c>m){
                    m = c;
                    year = p.first;
                }
            }
            else{
                c--;
            }
        }
        return year;
    }
};