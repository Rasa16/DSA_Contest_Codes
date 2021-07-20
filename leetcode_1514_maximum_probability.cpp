//https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<double, int>> pq;
        pq.push({0, start});
        
        vector<double> dist(n, INT_MIN);
        
        dist[start] = 1;
        
        while(!pq.empty()){
            int u = pq.top().second;
            double wt = pq.top().first;
            pq.pop();
            
            for(auto v : adj[u]){
                if(dist[v.first] < dist[u]*v.second){
                    dist[v.first] = dist[u]*v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        if(dist[end] < 0)
            return 0;
        return dist[end];
    }
};
