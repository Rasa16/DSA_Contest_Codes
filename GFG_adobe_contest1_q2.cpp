class Solution
{   
public:
    bool isSafe(int i, int j, int m, int n){
        if(i<0 || j<0 || i>m || j>n)
            return 0;
        return 1;
    }
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        queue<pair<int, int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        pair<int, int> p;
        
        for(int i = 0; i<m; i++){
            for(int j = 0 ;j<n; j++){
                if(matrix[i][j]){
                    p = {i, j};
                    q.push(p);
                }
            }
        }
        int r ,c;
        vector<bool> row(m, 0);
        vector<bool> col(n, 0);
        while(!q.empty()){
            p = q.front();
            q.pop();
            r = p.first;
            c = p.second;
            
            if(row[r] && col[c])
                continue;
            if(col[c] && !row[r]){
                for(int j = 0; j<n; j++){
                    if(isSafe(r, j, m, n) && matrix[r][j] == 0){
                        matrix[r][j] = 1;
                    }
                }
                row[r] = 1;
            }
            if(row[r] && !col[c]){
                for(int i = 0; i<m; i++){
                    if(isSafe(i, c, m, n) && matrix[i][c] == 0){
                        matrix[i][c] = 1;
                    }
                }
                col[c] = 1;
            }
            if(!row[r] && !col[c]){
                for(int j = 0; j<n; j++){
                    if(isSafe(r, j, m, n) && matrix[r][j] == 0){
                        matrix[r][j] = 1;
                    }
                }
                for(int i = 0; i<m; i++){
                    if(isSafe(i, c, m, n) && matrix[i][c] == 0){
                        matrix[i][c] = 1;
                    }
                }
                
                row[r] = 1;
                col[c] = 1;
            }
        }
    }
};