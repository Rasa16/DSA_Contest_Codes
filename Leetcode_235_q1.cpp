class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        int n = s.size();
        int j = 0;
        while(i<n){
            if(s[i] == ' '){
                j++;
                if(j == k){
                   s = s.substr(0, (i)); 
                    return s;
                }
            }
            i++;
        }
        if(i == n && j == k-1){
            return s;
        }
        return "";
    }
};