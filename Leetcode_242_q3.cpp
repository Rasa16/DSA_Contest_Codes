class Solution {
public:

        bool canReach(string s, int minJump, int maxJump) {
        
        vector<bool> visited(s.size(), false);
        queue<int> q;
        q.push(0);
        

        int farthest = 0;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(visited[t]) {
                continue;
            }
            visited[t] = true;

            for(int i = max(farthest, t + minJump); i <=  min(t + maxJump, (int)s.length() - 1) ; i++) {
                if(!visited[i] && s[i] == '0'){
                    q.push(i);
                }
            }
            
            farthest = max(farthest, t + maxJump);
        }
        
        return visited[s.size() - 1];
    }
    
//     bool canReach(string s, int minJump, int maxJump) {
//         if(s[s.length()-1] != '0')
//             return false;
        
//         vector<int> v;
//         for(int i = 0; i<s.length(); i++){
//             if(s[i] == '0')
//                 v.push_back(i);
//         }
        
//         int d = 0;
//         int i = 0;
//         bool flag = 1;
//         while(i<v.size()-1){
//             d = v[i+1] - v[i];
//             //cout<<d<<endl;
//              if(d>= minJump && d<= maxJump)
//                  i++;
//              else{
//                  flag = 0;
//                  break;
//              }  
//         }
//         if(flag)
//             return true;
//         else
//             return false;
//     }
 };
