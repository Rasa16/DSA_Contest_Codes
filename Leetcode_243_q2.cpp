class Solution {
public:
    string maxValue(string s, int x) {
        int i = 0;
        bool f = 0;
        int t;
        if(s[0] == '-'){
            i = 1;
            while(i < s.size()){
                t = s[i] - '0';
                if(t <= x)
                    i++;
                else{
                    f = 1;
                    string v = to_string(x);
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, s.size() - i);
                    s1 += v;
                    s1 += s2;
                    s = s1;
                    break;
                }
            }
            if(!f){
                string v = to_string(x);
                s += v;
            }
        }
        else{
            while(i < s.size()){
                t = s[i] - '0';
                if(t >= x)
                    i++;
                else{
                    f = 1;
                    string v = to_string(x);
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, s.size() - i);
                    s1 += v;
                    s1 += s2;
                    s = s1;
                    break;
                }
            }
            if(!f){
                string v = to_string(x);
                s += v;
            }
        }
        return s;
    }
};