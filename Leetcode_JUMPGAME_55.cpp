class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        
        queue<int> q;
        
        q.push(0);
        int farthest = 0;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            vis[t] = 1;
            
            for(int i = max(farthest+1,t+1); i<=min(t+nums[t], n-1); i++){
                if(!vis[i]){
                    q.push(i);
                }
            }
            farthest = max(farthest, t+nums[t]);
        }
        return vis[n-1];
    }
};