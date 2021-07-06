//https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	   vector<int> dist(n, INT_MAX);
	   dist[0] = 0;
	   
	   for(int i = 1; i<=n-1; i++){
	       bool notUpdate = true;
	       for(auto e : edges){
	           int u = e[0];
	           int v = e[1];
	           int wt = e[2];
	           
	           if(dist[u] != INT_MAX && dist[v] > dist[u] + wt){
	               dist[v] = dist[u] + wt;
	               notUpdate = false;
	           }
	       }
	       if(notUpdate)
	           break;
	   }
	   
	   for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            
            if(dist[v] > dist[u] + weight)
            {
                return true;
            }
        }
        
        return false;
	}
};
