class Solution
{

public:
    int xmod11(string x)
    {
       // code here
        int res = 0;
        for(int i = 0; i<x.length(); i++){
            res = (res*10 + x[i]-'0')%11;
        }
        return res;
    }
};
