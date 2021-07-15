class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        if(N == 1){
            return dict[0];
        }
        vector<int> adj[K];
        queue<int> q;
        
        for(int i = 0; i < N-1; i++)
        {
            string word1 = dict[i];
            string word2 = dict[i+1];
            
            for(int j = 0; j < min(word1.size(), word2.size()); j++)
            {
                if(word1[j] != word2[j])
                {
                    int index1 = word1[j] - 'a';
                    int index2 = word2[j] - 'a';
                    
                    adj[index1].push_back(index2);
                    
                    break;
                }
            }
        }
        vector<int> in(K, 0);
        for(auto i : adj){
            for(auto j : i){
                in[j]++;
            }
        }
        
        for(int i = 0; i<K; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        string res = "";
        while(!q.empty()){
            int t = q.front();
            q.pop();
            
            char ch = t + 'a';
            res += ch;
        
            
            for(auto v : adj[t]){
                    in[v]--;
                    if(in[v] == 0)
                        q.push(v);
            }
        }
        return res;
    }
};
