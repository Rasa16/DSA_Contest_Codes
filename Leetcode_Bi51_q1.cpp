class Solution {
public:
    string replaceDigits(string s) {
        string t = "abcdefghijklmnopqrstuvwxyz";
        
        string res = "";
        int n = 0;
        int m;
        char p;
        
        for(int i = 0; i<s.size(); i++){
            if(i % 2 == 0){
                res += (s[i]);
            }
            else{
                n = s[i] - '0';
                m = s[i-1] - 'a';
                p = t[m+n];
                res += (p);
            }
        }
        return res;
    }
};