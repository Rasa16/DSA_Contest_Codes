//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#

const int INF = 1e8;
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> res(V);
        vector<int> dist(V, INF);
        dist[S] = 0;
        for(int i = 0; i<V-1; i++){
            bool notUpdate = true;
            for(auto j : adj){
                int x = j[0];
                int y = j[1];
                int z = j[2];
                if(dist[y] > dist[x]+z){
                    dist[y] = dist[x] + z;
                    notUpdate = false;
                }
            }
            if(notUpdate)
                break;
        }
        return dist;
    }
};
