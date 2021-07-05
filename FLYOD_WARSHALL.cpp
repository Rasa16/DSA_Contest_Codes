//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

const int INF = 1e9;
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int i = 0; i<matrix.size(); i++){
	        for(int j = 0; j<matrix[0].size(); j++){
	            if(matrix[i][j] == -1)
	                matrix[i][j] = INF;
	        }
	    }
	    
	    for(int k = 0; k<matrix.size(); k++){
	        for(int i = 0; i<matrix.size(); i++){
	            for(int j = 0; j<matrix[0].size(); j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    for(int i = 0; i<matrix.size(); i++){
	        for(int j = 0; j<matrix[0].size(); j++){
	            if(matrix[i][j] == INF)
	                matrix[i][j] = -1;
	        }
	    }
	}
};
