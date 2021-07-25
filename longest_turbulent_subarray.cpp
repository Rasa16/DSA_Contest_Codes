//https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        dp1[0] = 1;
        dp2[0] = 1;
        int ans1 = 1;
        int ans2 = 1;
        for(int i = 1; i<n; i++){
            if(i & 1){
                if(arr[i] > arr[i-1])
                    dp1[i] = dp1[i-1] + 1;
                else
                    dp1[i] = 1;
            }
            else{
                if(arr[i] < arr[i-1])
                    dp1[i] = dp1[i-1] + 1;
                else
                    dp1[i] = 1;
            }
            ans1 = max(ans1, dp1[i]);
        }
        for(int i = 1; i<n; i++){
            if(i & 1){
                if(arr[i] < arr[i-1])
                    dp2[i] = dp2[i-1] + 1;
                else
                    dp2[i] = 1;
            }
            else{
                if(arr[i] > arr[i-1])
                    dp2[i] = dp2[i-1] + 1;
                else
                    dp2[i] = 1;
            }
            ans2 = max(ans2, dp2[i]);
        }
        return max(ans1, ans2);
    }
};
