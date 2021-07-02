//https://practice.geeksforgeeks.org/problems/course-schedule/0/?category[]=Graph&page=1&query=category[]Graphpage1
//https://leetcode.com/problems/course-schedule-ii/

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>> adj(n);
        vector<int> in(n, 0);
        queue<int> q;
        vector<int> res;
        int count = 0;
        for(int i = 0; i<m; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]]++;
        }
        for(int i = 0; i<n; i++){
            if(in[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            count++;
            res.push_back(t);
            for(auto i : adj[t]){
                in[i]--;
                if(in[i] == 0)
                    q.push(i);
            }
        }
        if(count != n)
        {
            return {};
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
