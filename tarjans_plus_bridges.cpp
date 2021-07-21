//https://leetcode.com/problems/critical-connections-in-a-network/submissions/
//Tarjan's + bridges

class Solution {
public:
    void DFS(int u, vector<vector<int>>& adjList, vector<bool> &visit,vector<vector<int>> &res,vector<int> &par,vector<int> &low,vector<int> &desc){
    static int time=0;
    visit[u]=true;
    desc[u]=low[u]=++time;
    
    for(auto v:adjList[u]){

        if(!visit[v]){
            par[v]=u;
            DFS(v,adjList,visit,res,par,low,desc);
            low[u] = min(low[u],low[v]);
            
            if(low[v]>desc[u]){
                res.push_back({u,v});
            }
        }else if(v!=par[u]){
            low[u] = min(low[u],desc[v]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adjList(n);
   for(int i=0;i<connections.size();i++){
       adjList[connections[i][0]].push_back(connections[i][1]);
       adjList[connections[i][1]].push_back(connections[i][0]);
   }
    vector<vector<int>> res;
    vector<int> par(n);
    vector<int> low(n,-1);
    vector<int> desc(n);
    vector<bool> visit(n,false);
    par[0]=-1;
    DFS(0,adjList,visit,res,par,low,desc);
    return res;
}
};
