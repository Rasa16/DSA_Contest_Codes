class Solution {
public:
    double dist(vector<int> v, pair<int, int> p){
        double x = pow((v[0] - p.first), 2.0);
        double y = pow((v[1] - p.second), 2.0);
        
        return pow((x+y), 0.5);
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        pair<int, int> p;
        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            p = {queries[i][0], queries[i][1]};
            double rad = (double)queries[i][2];
            double t;
            int c = 0;
            for(int j = 0; j<points.size(); j++){
                t = dist(points[j], p);
                if(t > rad)
                    continue;
                else
                    c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};