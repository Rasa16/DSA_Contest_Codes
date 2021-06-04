class Solution
{

public:
    int count(int x, int k){
        int c = 0;
        while(x>0){
            if(x%10 == k)
                c++;
            x = x/10;
        }
        return c;
    }
    int maxoccourence(int arr[], int n, int k)
    {
        // code here
        int ans = INT_MAX, t = INT_MIN, m;
        for(int i = 0; i<n; i++){
            m = count(arr[i], k);
            if(m > t){
                t = m;
                ans = arr[i];
            }
            else if(m == t){
                ans = min(ans, arr[i]);
            }
        }
        return ans;
    }
};