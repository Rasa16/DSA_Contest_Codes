int LDS(vector<int> arr){
    // Write your code here.
    int n = arr.size();
    int dp[n];
    int omax = 0;
    
    for(int i = 0; i<n; i++){
        int m = 0;
        for(int j = 0; j<i; j++){
            if(arr[j] > arr[i]){
                if(dp[j] > m)
                    m = dp[j];
            }
        }
        dp[i] = m+1;
        omax = max(omax, dp[i]);
    }
    return omax;
}