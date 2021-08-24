//https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>res;
        int i=0;
        sort(products.begin(),products.end());
        string search="";
        while(i<searchWord.length()){
            search+=searchWord[i];
            vector<string>s;
            for(int j=0;j<products.size();j++){
                string s1=products[j];
                string sub=s1.substr(0,i+1);
                if(sub==search && s.size()!=3){
                    s.push_back(products[j]);
                }
            }
            res.push_back(s);
            s.clear();
            i++;
        }
        return res;
    }
};
