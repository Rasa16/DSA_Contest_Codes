//https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1#

class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		vector<int> adj[10];
		adj[0] = {0,8};
		adj[1] = {1,2,4};
		adj[2] = {1,2,3,5};
		adj[3] = {2,3,6};
		adj[4] = {1,4,5,7};
		adj[5] = {2,4,5,6,8};
		adj[6] = {3,5,6,9};
		adj[7] = {4,7,8};
		adj[8] = {5,7,8,9,0};
		adj[9] = {6,8,9};
		
		long long dp[N+1][10] = {0};
		
		for(int i=0; i<=9; i++){
            dp[0][i]=0;
        }
        for(int i=0; i<=9; i++){
            dp[1][i]=1;
        }
		
		for(int i = 2; i<=N; i++){
		    for(int j = 0; j<10; j++){
		        for(auto k : adj[j]){
		            dp[i][j] += dp[i-1][k];
		        }
		    }
		}
		long long sum = 0;
		for(int i = 0; i<10; i++){
		    sum += dp[N][i];
		}
		return sum;
	}


};
