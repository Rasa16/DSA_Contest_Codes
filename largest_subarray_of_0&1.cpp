class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        for(int i = 0; i<N; i++)
            arr[i] = arr[i] == 0 ? -1:1;
        unordered_map<int, int> mp;
        int sum = 0;
        int res = 0;
        
        for(int i = 0; i<N; i++){
            sum += arr[i];
            if(sum == 0)
                res = i+1;
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            else if(mp.find(sum) != mp.end())
                res = max(res, (i-mp[sum]));
        }
        return res;
    }
};
