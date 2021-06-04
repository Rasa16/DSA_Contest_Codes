class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        
        int amt = 0;
        int ans = 0;
        for(int i = 0; i<costs.size(); i++){
            if(amt+costs[i] <= coins){
                amt += costs[i];
                ans++;
                if(amt == coins)
                    break;
            }
        }
        return ans;
    }
};