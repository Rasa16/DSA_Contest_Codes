class Solution {
public:
    bool check(string s){
        if(s[0] == s[1] || s[1] == s[2] || s[0] == s[2])
            return false;
        return true;
    }
    int countGoodSubstrings(string s) {
        if(s.size() < 3)
            return false;
        string t;
        int ans = 0;
        for(int i = 0; i<s.size()-2; i++){
            t = s.substr(i, 3);
            if(check(t))
                ans++;
        }
        return ans;
    }
};