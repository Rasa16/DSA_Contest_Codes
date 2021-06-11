// class Solution {
// public:
//     int mod = 1e9+7;
//     int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         vector<int> diff(n ,0);
//         pair<int, int> p = {0, -1};
//         for(int i = 0; i<n; i++){
//             diff[i] = abs(nums1[i]-nums2[i]);
//             if(diff[i] > p.first){
//                 p.first = diff[i];
//                 p.second = i;
//             }
//         }
        
//         if(p.first == 0){
//             return 0;
//         }
        
//         int t = nums2[p.second];
//         int m = INT_MAX;
//         int r;
//         for(int i = 0; i<n; i++){
//             if(abs(t-nums1[i]) < m){
//                 m = abs(t-nums1[i]);
//                 r = nums1[i];
//             }
//         }
//         nums1[p.second] = r;
        
//         diff[p.second] = m;
        
//         t = 0;
//         for(int i = 0; i<n; i++){
//             t += diff[i];
//         }
//         return t%mod;
//     }
// };
class Solution {
public:
    #define ll long long int
    int mod=1000000007;
    int nearest(vector<int>&v,int k)
    {
        int diff=INT_MAX,i=0,j=v.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            int d=abs(v[mid]-k);
            diff=min(d,diff);
            if(v[mid]<k)
                i=mid+1;
            else
                j=mid-1;
        }
        return diff;
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>temp=nums1;
        sort(temp.begin(),temp.end());
        ll sum=0,n=nums1.size();
        for(int i=0;i<n;i++)
            sum+=abs(nums1[i]-nums2[i]);
        ll res=sum;
        for(int i=0;i<n;i++)
        {
            ll diff=nearest(temp,nums2[i]);
            ll curr=sum-abs(nums1[i]-nums2[i])+diff;
            res=min(res,curr);
        }
        return res%mod;
    }
};