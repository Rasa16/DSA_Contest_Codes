//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118511/offering/1381537?leftPanelTab=0

#include<bits/stdc++.h>

bool isSafe(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

int bfs(vector<vector<int>>& grid, int i, int j, int n, int m){
    
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
    
    queue<pair<int, int>> q;
    int c = 1;
    q.push({i, j});
    grid[i][j] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i<8; i++){
            int p = x+dx[i];
            int r = y+dy[i];
            
            if(isSafe(p, r, n, m) && grid[p][r]){
                q.push({p, r});
                c++;
                grid[p][r] = 0;
            }
        }
    }
    return c;
}

int maxAreaOfIsland(vector<vector<int>>& grid, int n, int m) {
    // Write your code here.
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j])
                ans = max(ans, bfs(grid, i, j, n, m));
        }
    }
    return ans; 
}
