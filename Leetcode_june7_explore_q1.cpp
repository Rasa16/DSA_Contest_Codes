class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        set<int> s;
        for(auto i:nums)
            s.insert(i);
        vector<int> v;
        for(auto i:s)
            v.push_back(i);
        int size = v.size();
        int i = 0, j = 0;
        int ans = 0;
        while(j<size-1){
            if(v[j+1] - v[j] == 1){
                j++;
            }
            else{
                ans = max(ans, j-i+1);
                j++;
                i = j;
            }
        }
        ans = max(ans, j-i+1);
        return ans;
    }
};