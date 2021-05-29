class Solution{   
public:
    void dfs(vector<int> adj[], int u, vector<bool> &vis, long long &sum, vector<int> &Values){
        vis[u] = 1;
        
        sum += Values[u-1];
        
        for(auto v:adj[u]){
            if(!vis[v]){
                dfs(adj, v, vis, sum, Values);
            }
        }
    }
    long long solve(int V,int E,vector<int> Values,vector<vector<int>> Edges){
      //code here
        vector<int> adj [V+1];
        for(int i = 0; i<E; i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        vector<bool> vis(V+1, 0);
        
        long long maxsum = 0;
        
        
        for(int i = 1; i<=V; i++){
            long long sum = 0;
            if(!vis[i]){
                dfs(adj, i, vis, sum, Values);
            }
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};