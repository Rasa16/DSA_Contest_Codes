class Solution
{
public:
    string smallestnum(string N)
    {
        //code here
        int freq[10] = {0};
        vector<int> v;
        int t;
        for(int i = 0; i<N.size(); i++){
            t = N[i] - '0';
            v.push_back(t);
        }
        
        sort(v.begin(), v.end());
        
        string res = "";
        string temp;
        bool f = 1;
        int zero = 0;
        for(int i = 0; i<v.size(); i++){
            if(v[i] == 0){
                zero++;
            }
            else if(f){
                temp = to_string(v[i]);
                res += temp;
                f = 0;
                while(zero--){
                    temp = to_string(0);
                    res += temp;
                }
            }
            else{
                temp = to_string(v[i]);
                res += temp;
            }
        }
        return res;
    }
};