class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
       vector<int> res(3);
        int m = 0, t = 1;
         m = max(memory1, memory2);
        
        while(m>0 && m>=t){
            if(memory1>=memory2)
                memory1 -= t;
            else
                memory2 -=t;
            t++;
            m = max(memory1, memory2);
        }
        
        res = {t, memory1, memory2};
        return res;
    }
};