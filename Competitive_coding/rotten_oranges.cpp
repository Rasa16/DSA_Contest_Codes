//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    bool isSafe(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int f = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1)
                    f++;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1, 1, 0, 0};
        
        int ans = 0;
        if(f == 0)
            return 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i = 0; i<4; i++){
                    int xx = x+dx[i];
                    int yy = y+dy[i];
                    
                    if(isSafe(xx, yy, n, m, grid) && grid[xx][yy] == 1){
                        f--;
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }
            
            ans++;
            if(f == 0)
                return ans;
        }
        if(f > 0)
            return -1;
        return ans;
    }
};
