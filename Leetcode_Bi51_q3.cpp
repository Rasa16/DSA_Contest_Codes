class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr.size() == 1)
            return 1;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if(arr[0] != 1)
            arr[0] = 1;
        if(arr[1] != 2)
            arr[1] = 2;
        for(int i = 2; i<n; i++){
            if(abs(arr[i] - arr[i-1]) <= 1)
                continue;
            else{
                arr[i] = min(arr[i], arr[i-1]+1);
            }
        }
        return arr[n-1];
    }
};