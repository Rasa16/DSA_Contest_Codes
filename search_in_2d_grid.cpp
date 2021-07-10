//https://leetcode.com/problems/search-a-2d-matrix-ii/
//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377946

class Solution {
public:
    bool binary(vector<int> v, int x){
        int l = 0, h = v.size()-1;
        while(l<=h){
            int m = (l+h)/2;
            if(v[m] == x)
                return true;
            else if(v[m] > x)
                h = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n = arr.size();
        int m = arr[0].size();
        cout<<n<<m<<endl;
        int row = -1;
        for(int i = 0; i<n; i++){
            int j = m-1;
            if(arr[i][j] < x)
                continue;
            else{
                row = i;
                break;
            }
        }
        if(row != -1){
            while(row < n){
                if(binary(arr[row], x))
                    return true;
                row++;
            }
        }
        
        return false;
        
    }
};
