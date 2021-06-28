//https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

long long int count(long long int n)
{
	long long int dp[n+1],i;
	memset(dp, 0, sizeof(dp));
	dp[0]=1;                 // If 0 sum is required number of ways is 1.
	
	// Your code here
	int arr[3] = {3, 5, 10};
	for(int i = 0; i<3; i++){
	    for(int j = arr[i]; j<=n; j++){
	        if(dp[j-arr[i]] > 0)
	            dp[j] = dp[j] + dp[j-arr[i]];
	    }
	}
	
	return dp[n];
}
