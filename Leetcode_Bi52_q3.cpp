class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& s) {
        int m = s.size();
        int n = s[0].size();
        for(auto &x:s){
            int j=x.size()-1;
            for(int i=x.size()-1;i>=0;i--){
                if(x[i]=='.'){
                    continue;
                }
                else if(x[i]=='*'){
                    j=i-1;
                }
                else{
                    if(x[j]=='.'){
                        x[i]='.';
                        x[j]='#';
                        j--;
                    }
                    else{
                        j=i-1;
                    }
                }
            }
        }
        /*for(int i = 0; i<m; i++){
            for(int j = 0;j <n; j++){
                cout<<s[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        
        vector<vector<char>> res(n, vector<char>(m));
        int q = 0, k = 0;
        for(int i = m-1; i>=0; i--){
            q = m-1-i;
            k = 0;
            for(int j = 0; j<n; j++){
                res[k++][q] = s[i][j];
            }
        }
        
        return res;
    }
};