class Solution {
public:
    bool isvalid(vector<int> v, int h, int k){
        double t = 0;
        for(auto i:v){
           double x = double(i)/k;
            t+=ceil(x);
            if(t>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int l = 0, r = piles[n-1];
        int ans = INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            if(isvalid(piles, h, mid)){
                ans = min(ans, mid);
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};