class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> dq;
        for(int i = 1; i<=n; i++){
            dq.push_back(i);
        }
        int t = 1;
        while(dq.size() != 1){
            t = 1;
            while(t != k){
                dq.push_back(dq.front());
                t++;
                dq.pop_front();
            }
            dq.pop_front();
        }
        return dq.front();
    }
};