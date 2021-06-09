class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        //vector<int> v;
        int l = 0, n = A.size();
        int r = n-1;
        while(l<r){
            if(A[l] + A[r] == target)
                break;
            else if(A[l] + A[r] < target)
                l++;
            else
                r--;
        }
        return {l+1, r+1};
    }
};