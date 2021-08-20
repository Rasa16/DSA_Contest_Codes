//https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> m;
        int i = 0, j = 0;
        while(i<9){
            j = 0;
            m.clear();
            while(j<9){
                if(board[i][j] == '.' || board[i][j] == ',')
                    j++;
                else if(m.find(board[i][j]) != m.end())
                    return false;
                else{
                    m[board[i][j]]++;
                    j++;
                } 
            }
            i++;
        }
        j = 0;
        while(j<9){
            i = 0;
            m.clear();
            while(i<9){
                if(board[i][j] == '.' || board[i][j] == ',')
                    i++;
                else if(m.find(board[i][j]) != m.end())
                    return false;
                else{
                    m[board[i][j]]++;
                    i++;
                }  
            }
            j++;
        }
        
        for(int i = 0; i<9; i= i+3){
            for(int j = 0; j<9; j= j+3){
                m.clear();
                for(int r = i; r<i+3; r++){
                    for(int c = j; c<j+3; c++){
                        if(board[r][c] == '.' || board[r][c] == ',')
                            continue;
                        else if(m.find(board[r][c]) != m.end())
                            return false;
                        else
                            m[board[r][c]]++;
                    }
                }
            }
        }
        return true;
    }
};
