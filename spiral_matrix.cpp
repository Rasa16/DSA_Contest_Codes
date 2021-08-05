//https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r = n;
        int c = n;
        int row = 0;
        int col = 0;
        vector<vector<int>> matrix(n, vector<int>(n));
        int x = 1;
        
        while(row < r && col < c){
            for(int i = col; i<c; i++){
                matrix[row][i] = x++;
            }
            row++;
            
            for(int j = row; j<r; j++){
                matrix[j][c-1] = x++;
            }
            c--;
            
            if(row < r){
                for(int i = c-1; i>=col; i--){
                    matrix[r-1][i] = x++;
                }
                r--;
            }
            
            if(col < c){
                for(int j = r-1; j>=row; j--){
                    matrix[j][col] = x++;
                }
                col++;
            }
        }
        return matrix;
    }
};
