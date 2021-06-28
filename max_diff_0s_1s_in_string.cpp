//https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1#
//https://www.youtube.com/watch?v=_k_Codwq1ls&t=15s

class Solution{
public:	
	int maxSubstring(string arr)
	{
	    // Your code goes here
	    int n = arr.size();
	    int omax = INT_MIN;
	    int sum = 0;
	    
	    for(int i = 0; i<n; i++){
	        int x = arr[i] == '0' ? 1 : -1;
	        
	        sum += x;
            omax = max(omax , sum);
            if(sum < 0) sum = 0;
	    }
	    return omax;
	}
};
