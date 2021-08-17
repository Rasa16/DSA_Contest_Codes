//https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum1;
        unordered_map<int, int> sum2;
        
        for (const auto &num1: nums1)
        {
            for (const auto &num2: nums2)
            {
                sum1[num1 + num2] += 1;
            }
        }
        
        for (const auto &num3: nums3)
        {
            for (const auto &num4: nums4)
            {
                sum2[num3 + num4] += 1;
            }
        }
        
        int result = 0;
        for (const auto &it: sum1)
        {
            if (sum2.find(-it.first) != sum2.end())
            {
                result += (it.second * sum2[-it.first]);
            }
        }
        
        return result;
    }
};
