class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0, ans;
        for(int i = 0; i<n; i++)
            sum += chalk[i];
        if(k%sum == 0)
            return 0;
        else
            k = k%sum;
        
        for(int i = 0; i<n; i++){
            if(k < chalk[i]){
                ans = i;
                break;
            }
            else 
                k = k-chalk[i];
        }
        return ans;
    }
};