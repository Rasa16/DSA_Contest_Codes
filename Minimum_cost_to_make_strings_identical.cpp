//https://practice.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1#

class Solution{

	public:
	int LCS(string X, string Y){
	    int x = X.size();
	    int y = Y.size();
	    
	    // your code here
        int dp[x+1][y+1];
        
        for(int i = 0; i<=x; i++){
            dp[i][y] = 0;
        }
        for(int j = 0; j<=y; j++){
            dp[x][j] = 0;
        }
        
        for(int i = x-1; i>=0; i--){
            for(int j = y-1; j>=0; j--){
                if(X[i] == Y[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
	}
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes here
	    
	    int lcs = LCS(X, Y);
	    //cout<<lcs<<endl;
	    int ans = costX*(X.size() - lcs) + costY*(Y.size() - lcs);
	    
	    return ans;
	}
  

};