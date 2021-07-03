//https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

class Solution {
  public:
    int kadane(int arr[], int n){
        int sum = 0;
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            if(sum + arr[i] >= arr[i])
                sum += arr[i];
            else
                sum = arr[i];
            ans = max(sum, ans);
        }
        return ans;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ans = INT_MIN;
        int t[C];
        int m;
        for(int i = 0; i<R; i++){
            memset(t, 0, sizeof(t));
            for(int k = i; k<R; k++){
                for(int j = 0; j<C; j++){
                    t[j] += M[k][j];
                }
                m = kadane(t, C);
                //cout<<m<<" ";
                ans = max(m, ans);
            }
        }
        return ans;
    }
};
