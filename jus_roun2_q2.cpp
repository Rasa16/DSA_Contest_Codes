#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include<unordered_map>
#define INT_MAX 9999
using namespace std;

int dfs(vector<vector<int>> adj,int total,int s,int d,vector<bool> &visited){
    if(s==d) return 0;
    visited[s]=1;
    int res=INT_MAX;
    for(int i=0;i<total;i++){
        if(adj[s][i]!=INT_MAX && !visited[i]){
            int temp=dfs(adj,total,i,d,visited);
            if(temp<INT_MAX){
                res=min(res,adj[s][i]+temp);
            }
        }
    }
    visited[s]=0;
    if(res == INT_MAX)
        return -1;
    return res;
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
    vector<vector<int>> adj(total+1,vector<int> (total+1,INT_MAX));
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[m[u]][m[v]]=w;
    }
    int follower,following;
    cin>>follower>>following;
    follower=m[follower];
    following=m[following];
    vector<bool> visited(total+1,0);
    visited[follower]=1;
    cout<<dfs(adj,total,follower,following,visited);
    return 0;
}
