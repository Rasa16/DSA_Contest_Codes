class Solution
{
public:
    string set(int n){
        string res = "";
        int rem;
        while(n>0){
            rem = n%2;
            n = n/2;
            res = to_string(rem)+res;
        }
        return res;
    }
    int setBits(int N)
    {
        // Write Your Code here
        string res = set(N);
        int c = 0;
        for(int i = 0; i<res.size(); i++){
            if(res[i] == '1')
                c++;
        }
        return c;
    }
};