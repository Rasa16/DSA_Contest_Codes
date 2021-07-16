//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118511/offering/1381534?leftPanelTab=0

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool cycle(vector<vector<int>> adj, int u, vector<bool> &vis, int parent){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            if(cycle(adj, v, vis, u))
                return true;
        }
        else if(v != parent)
            return true;
    }
    return false;
}

bool isTree(vector<vector<int>> &adj, int V)
{
    // Write your code here.
    vector<bool> vis(V, 0);
    
    if(cycle(adj, 0, vis, -1))
        return false;
    for(int i = 0; i<V; i++){
        if(!vis[i])
            return false;
    }
    return true;
}

// Do not change this part of the code. You only need to complete the isTree function above.
int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (isTree(adj, v))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}
