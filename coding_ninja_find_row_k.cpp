
int FindSpecialRow(int **mat, int N) {
   
  /* 
   Don't write main().
   Don't read input, it is passed as function argument.
   Don't print anything, just make the necessary changes in the input array.
   Write your code here.
  */
    bool flag = 1;
    for(int i = 0; i<N; i++){
        flag = 1;
        for(int j = 0; j<N; j++){
            if(i == j)
                continue;
            if(mat[i][j] == 1)
                flag = 0;
        }
        if(flag){
            int k = i;
            for(int s = 0; s<N; s++){
                if(k == s)
                    continue;
                if(mat[s][k] == 0){
                    flag = 0;
                    break;
                }    
            }
            if(flag)
                return k; 
        }
    }
	return -1;
}