class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int i = 0, j = 0;
        int n = s.size();
        
        string res = "";
        
        int t = INT_MAX;
        int ans = 0;
        
        while(i<n && j<n){
            m[s[i]]++;
            i++;
            while(m[s[i-1]] > 1){
                m[s[j]]--;
                j++;
            }
            t = i-j;
            ans = max(ans, t);
        }
        return ans;
    }
};