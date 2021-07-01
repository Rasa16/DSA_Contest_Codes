class Solution {
public:
    bool isSafe(int i, int j , int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        int dx[4] = {-1, 1, 0 ,0};
        int dy[4] = {0, 0, -1, 1};
        int t = image[sr][sc];
        pair<int, int> p = {sr, sc};
        q.push(p);
        vis[sr][sc] = 1;
        image[sr][sc] = newColor;
        
        while(!q.empty()){
            p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;
            
            for(int i = 0; i<4; i++){
                if(isSafe(x+dx[i], y+dy[i], m, n) && image[x+dx[i]][y+dy[i]] == t && !vis[x+dx[i]][y+dy[i]]){
                    vis[x+dx[i]][y+dy[i]] = 1;
                    q.push({x+dx[i], y+dy[i]});
                    image[x+dx[i]][y+dy[i]] = newColor;
                }
            }
        }
        return image;
    }
};
