class Solution
{
public:
    bool rearrangeString(string S)
    {
        //code here
        int len = S.size();
        vector<int> freq(26, 0);
        for(int i = 0; i<len; i++){
            freq[S[i] - 'a']++;
        }
        int m = *max_element(freq.begin(), freq.end());
        int mid = len/2;
        if(len & 1){
            if(m > mid + 1)
                return false;
            else
                return true;
        }
        else{
            if(m > mid)
                return false;
            else
                return true;
        }
        return true;
    }
};