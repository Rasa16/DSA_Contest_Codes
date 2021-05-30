class Solution {
public:
    int cal(string s){
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            ans = ans*10 + (s[i] - 'a');
        }
        return ans;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int n1 = cal(firstWord);
        int n2 = cal(secondWord);
        
        int n3 = cal(targetWord);
        
        //cout<<n1<<" "<<n2<<" "<<endl;
        
        if((n1 + n2) == n3)
            return true;
        return false;
    }
};