class Solution{
public:
    int maxSubarraySum(int arr[], int N){
        // Your code here
        int sum = 0;
        int omax = 0;
        
        for(int i = 0; i<N; i++){
            if(sum >= 0){
               sum += arr[i]; 
            }
            else{
                sum = arr[i];
            }
            omax = max(sum, omax);
        }
         return omax;   
    }
};