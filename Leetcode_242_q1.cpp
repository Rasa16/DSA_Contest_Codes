class Solution {
public:
    bool checkZeroOnes(string s) {
        int one_cc = 0, one_oc = 0;
        int zero_cc = 0, zero_oc = 0;
        
        bool flag = 0;
        if(s[0] == '1'){
            flag = 1;
            one_cc = 1;
            one_oc = 1;
        }
        else{
            zero_cc = 1;
            zero_oc = 1;
        }
        
        for(int i = 1; i<s.length(); i++){
            if(s[i] == '1'){
                if(flag == 1){
                    one_cc++;
                }
                else{
                    one_cc = 1;
                    flag = 1;
                }
                one_oc = max(one_oc, one_cc);
            }
            else{
                if(flag == 0){
                    zero_cc++;
                }
                else{
                    zero_cc = 1;
                    flag = 0;
                }
                zero_oc = max(zero_oc, zero_cc);
            }
        }
        
        if(one_oc > zero_oc)
            return 1;
        return 0;
    }
};