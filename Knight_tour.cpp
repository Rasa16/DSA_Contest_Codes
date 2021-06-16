bool isSafe(int i , int j, int n){
    if(i<0 || j<0 || i>n || j>n)
        return false;
    return true;
}
int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    // Write your code here.
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(size+1, vector<bool> (size+1, 0));
    int count = 0;
    
    pair<int, int> s = knightPosition;
    pair<int, int> d = targetPosition;
    
    q.push(s);
    q.push({-1, -1});
    int i,j;
    while(!q.empty()){
        s = q.front();
        q.pop();

        if(s.first == d.first && s.second == d.second)
            return count;
        else if(s.first == -1 && s.second == -1){
            count++;
            q.push({-1, -1});
        }
        else{
            i = s.first;
            j = s.second;
            if(isSafe(i-2, j+1, size) && !vis[i-2][j+1]){
                q.push({i-2, j+1});
                vis[i-2][j+1] = 1;
            }
            if(isSafe(i-1, j+2, size) && !vis[i-1][j+2]){
                q.push({i-1, j+2});
                vis[i-1][j+2] = 1;
            }
                
            if(isSafe(i+1, j+2, size) && !vis[i+1][j+2]){
                q.push({i+1, j+2});
                vis[i+1][j+2] = 1;
            }
                
            if(isSafe(i+2, j+1, size) && !vis[i+2][j+1]){
                q.push({i+2, j+1});
                vis[i+2][j+1] = 1;
            }
                
            if(isSafe(i+2, j-1, size) && !vis[i+2][j-1]){
                q.push({i+2, j-1});
                vis[i+2][j-1] = 1;
            }
                
            if(isSafe(i+1, j-2, size) && !vis[i+1][j-2]){
                q.push({i+1, j-2});
                vis[i+1][j-2] = 1;
            }
                
            if(isSafe(i-1, j-2, size) && !vis[i-1][j-2]){
                q.push({i-1, j-2});
                vis[i-1][j-2] = 1;
            }
                
            if(isSafe(i-2, j-1, size) && !vis[i-2][j-1]){
                q.push({i-2, j-1});
                vis[i-2][j-1] = 1;
            }   
        }
        
    }
    return count;
}