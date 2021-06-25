class Solution{
public:	
	int search(int arr[], int N){
	    //code
	    int i;
	    for(i = 0; i<N; i = i+2){
	        if(arr[i] != arr[i+1])
	            break;
	    }
	    return arr[i];
	}
};