//https://practice.geeksforgeeks.org/problems/max-length-chain/1#

/*You are required to complete this method*/
bool logic(struct val p, struct val q){
    return p.first < q.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
     sort(p, p+n, logic);
     vector<int>v(n,1);
     for(int i=1; i<n; i++){
         for(int j=0; j<i; j++){
             if(p[i].first > p[j].second && v[i] < v[j]+1){
                 v[i] = v[j]+1;
             }
         }
     }
     auto it = v.begin();
     int ans = INT_MIN;
     for(; it!= v.end(); it++) ans = max(ans, *it);
     return ans;
    
}
