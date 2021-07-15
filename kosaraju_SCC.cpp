//https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
void dfstrans(vector<int> adj[], vector<bool> &vis, int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfstrans(adj, vis, v);
        }
    }
}

void dfs(vector<int> adj[], vector<bool> &vis, int u, stack<int> &st){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(adj, vis, v, st);
        }
    }
    st.push(u);
}
void transpose(vector<int> adj[], vector<int> trans[], int v){
    for(int i = 0; i<v; i++){
        for(auto j : adj[i]){
            trans[j].push_back(i);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
    vector<int> adj[v];
    vector<int> trans[v];
    int e = edges.size();
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        
        adj[u].push_back(v);
    }
    vector<bool> vis(v, 0);
    stack<int> recst;
    //stack with finishing times
    for(int i = 0; i<v; i++){
        if(!vis[i])
            dfs(adj, vis, i, recst);
    }
    
    //transpose adjacency list
    transpose(adj, trans, v);
   vector<bool> vis1(v, 0);
    int c = 0;
    //applying dfs on transpose based on stack
    while(!recst.empty()){
        int t = recst.top();
        recst.pop();
        if(!vis1[t]){
            c++;
            dfstrans(trans, vis1, t);
        }
    }
    return c;
    
}
