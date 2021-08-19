class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || n == 1)
            return;
        k = k%n;
        
        deque<int> dq;
        for(auto x : nums)
            dq.push_back(x);
        
        while(k--){
            int t = dq.back();
            dq.pop_back();
            dq.push_front(t);
        }
        nums.clear();
        while(!dq.empty()){
            int t = dq.front();
            dq.pop_front();
            nums.push_back(t);
        }
    }
};
