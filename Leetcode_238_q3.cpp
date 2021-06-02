class Solution {
public:
    int longestBeautifulSubstring(string word) {
       string vowel = "aeiou";
        int m = 0;int j,k;
        for(int i = 0; i<word.size(); i++){
            if(word[i] == 'a' && i == 0 || word[i] == 'a' && word[i-1] != 'a'){
                k = 0;
                j = i;
                while(j<word.size()){
                    if(word[j] == vowel[k]){
                        j++;
                        if(j == word.size() && k == 4)
                            m = max(m, j-i);
                            
                    }
                        
                    else{
                        if(k == 4 || k == 5){
                            m = max(m, j-i);
                            break;
                        }
                            
                        else{
                            if(word[j] == vowel[k+1])
                                k++;
                            else
                                break;
                        }
                    }
                }
            }
        }
        return m;
    }
};