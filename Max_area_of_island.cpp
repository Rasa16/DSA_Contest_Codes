//https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
//https://leetcode.com/problems/max-area-of-island/

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int count(int i, int j, vector<vector<int>> &grid){
        if(i<0 || i>=grid.size()) return 0;
        if(j<0 || j>=grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;
        
        int ct = 1;
        grid[i][j] = 0;
        ct += count(i-1, j, grid);
        ct += count(i+1, j, grid);
        ct += count(i, j-1, grid);
        ct += count(i, j+1, grid);
        ct += count(i+1, j+1, grid);
        ct += count(i-1, j+1, grid);
        ct += count(i+1, j-1, grid);
        ct += count(i-1, j-1, grid);
        
        return ct;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                int f = count(i, j, grid);
                ans = max(ans, f);
            }
        }
        return ans;
    }
};
