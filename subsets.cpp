//https://leetcode.com/problems/subsets/

Solution {
public:
    int getXth( int n, int x ){
        return ( n & (1 << x))  >=1 ? 1 : 0 ; 
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        
       vector< vector<int> > allSubs ; 
        
        for( int i =0 ; i < (1 << (int)nums.size())  ; i++ ){
            
            vector<int> sub ;
            
            for( int j = 0 ; j < (int)nums.size() ; j++){
               
                if( getXth( i, j) == 1 )
                    sub.push_back( nums[j] ) ;
            }
            
            allSubs.push_back( sub ) ;
            
           }
         return allSubs ; 

    }
};
