class Solution {
public:
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int n = arr.size();
//         int omax = 0;
//         int *dp = new int[n];
//         dp[0] = 1;
//         for(int i = 1; i<n; i++){
//             int m = 0;
//             for(int j = i-1; j>=0; j--){
//                 if(arr[i]-arr[j] == difference){
//                     if(dp[j]>m){
//                         m = dp[j];
//                         break;
//                     }
                        
//                 }
//             }
//             dp[i] = m+1;
//             omax = max(omax, dp[i]);
//         }
//         return omax;
//     }
    int longestSubsequence(vector<int>& a, int d) 
    {
        //O(n)
        int ans = 0;
        
        unordered_map<int,int> dp; //length of a.p sequence end at value map->key
        //dp[0] = 1;
        for(int i = 0; i<a.size(); i++)
        {
            dp[a[i]] = dp[a[i] - d] + 1; //note dp is unordered_map
            ans = max(ans,dp[a[i]]);
        }
        
        return ans;
    }
};