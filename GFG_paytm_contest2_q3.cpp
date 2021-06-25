bool DFSRec(vector<int> adj[], int s, bool vis[], bool recst[]){
    vis[s] = true;
    recst[s] = true;
    
    for(auto i:adj[s]){
        if(vis[i] == false && DFSRec(adj, i, vis, recst))
            return true;
        else if(recst[i] == true)
            return true;
    }
    recst[s] = false;
    return false;
}

bool isCyclic(int N, vector<int> adj[])
{
    // Your code here
    bool vis[N] = {0};
    bool recst[N] = {0};
    
    for(int i = 0; i<N; i++){
        if(vis[i] == false && DFSRec(adj, i, vis, recst))
            return true;
    }
    return false;
}
