class Solution {
public:
    int largestsubstring(string s) {
        
        //Your code here
        int f[256] = {0};
        int i = 0, j = 0;
        int ans = 0;
        
        while(j < s.size()){
            if(f[s[j]] > 0){
                ans = max(ans, (j-i));
                while(s[i] != s[j]){
                    f[s[i]]--;
                    i++;
                }
                i++;
                j++;
            }
            else{
                f[s[j]]++;
                j++;
            }
        }
        return max(ans, (j-i));
    }
};