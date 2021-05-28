class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string>> v;
        int n = s.size();
        int i = 0, j = 0;
        
        while(i<n && j<n){
            if(s[j]>='0' && s[j]<='9'){
                int num = s[j] - '0';
                string t = s.substr(i, j-i);
                pair<int, string> p = {num, t};
                
                v.push_back(p);
                
                j = j+2;
                i = j;
            }
            else{
                j++;
            }
        }
        string res = "";
        sort(v.begin(), v.end());
        
        for(int i = 0; i<v.size()-1; i++){
            res += v[i].second;
            res.push_back(' ');
        }
        res += v[v.size()-1].second;
        return res;
    }
};