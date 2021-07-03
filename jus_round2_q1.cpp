#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include<unordered_map>
using namespace std;

bool bfs(vector<int> adj[],int total,int s,int d){
    vector<bool> visited(total,0);
    visited[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        if(u==d) return true;
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]==false){
                visited[adj[u][i]]=true;
                q.push(adj[u][i]);
            }
        }
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int total;
    cin>>total;
    unordered_map<int,int> m;
    for(int i=0;i<total;i++){
        int temp;
        cin>>temp;
        m[temp]=i;
    } 
    vector<int> adj[total];
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[m[u]].push_back(m[v]);
    }
    int s,d;
    cin>>s>>d;
    s=m[s];
    d=m[d];
    cout<<bfs(adj,total,s,d);
    return 0;
}
