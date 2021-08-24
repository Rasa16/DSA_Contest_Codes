//https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> m;
        int n = barcodes.size();
        for(auto i : barcodes)
            m[i]++;
        priority_queue<pair<int, int>> pq;
        for(auto v : m){
            pq.push({v.second, v.first});
        }
        
        vector<int> res(n, 0);
        int idx = 0;
        while(!pq.empty())
        {
            int c=pq.top().first;       
            int x=pq.top().second;        
            while(c--)
            {
                if(idx>=n)  
                    idx=1;          
                res[idx]=x;               
                idx+=2;
            }

            pq.pop();
        }

        return res;
    }
};
