//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
//https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> sor(n, n);
        vector<int> sol(n, -1);
        
        stack<int> st, st1;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                sor[i] = n;
            }
            else{
                sor[i] = st.top();
                st.push(i);
            }
        }
        
        for(int i = 0; i<n; i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                st1.push(i);
                sol[i] = -1;
            }
            else{
                sol[i] = st1.top();
                st1.push(i);
            }
        }
        
        long long ans = 0;
        long long t;
        for(int i = 0; i<n; i++){
            t = sor[i] - sol[i] - 1;
            t *= arr[i];
            
            ans = max(t, ans);
        }
        return ans;
    }
};
