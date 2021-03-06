class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    dp[0] = arr[0];
	    
	    int res = dp[0];
	    
	    for(int i = 1; i < n; i++)
	    {
	        dp[i] = arr[i];
	        
	        for(int j = 0; j < i; j++)
	        {
	            if(arr[j] < arr[i])
	            {
	                dp[i] = max(dp[i], arr[i] + dp[j]);
	            }
	        }
	        
	        res = max(res, dp[i]);
	    }
	    
	    return res;
	}  
};