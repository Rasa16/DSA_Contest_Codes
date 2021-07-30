//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
            }
            if(nums[mid]>nums[e]){
                s=mid+1;
            }
            if(nums[mid]<nums[e]){
                e=mid-1;
            }
        }
        return 0;
    }
};
