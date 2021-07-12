//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0

vector<int> shortestpathutil(vector<vector<int>> adj,int v,int s,int t){
    vector<bool> visited(v+1,0);
    visited[s]=1;
    queue<pair<int,vector<int>>> q;
    q.push({s,{s}});
    while(!q.empty()){
        int u=q.front().first;
        vector<int> a = q.front().second;
        q.pop();
        if(u==t){
            return a;
        }
        for(int i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]==0){
                visited[adj[u][i]]=1;
                a.push_back(adj[u][i]);
                q.push({adj[u][i],a});
                a.erase(a.begin()+a.size()-1);
            }
        }
    }
    return {};
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    return shortestpathutil(adj,n,s,t);
}
