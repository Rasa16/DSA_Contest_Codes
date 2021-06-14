class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> st;
       vector<int> s(n);
       st.push(0);
       
       s[0] = 1;
       for(int i = 1; i<n; i++){
           while(!st.empty() && price[st.top()] <= price[i]){
               st.pop();
           }
           if(st.empty())
                s[i] = i+1;
            else
                s[i] = i - st.top();
            st.push(i);
       }
       return s;
    }
};
