/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    /**
     * 暴力求解
     */
    // int subarraySum(vector<int> &nums, int k)
    // {
    //     vector<vector<int>> result;
        
    //     for(auto iter = nums.begin(); iter != nums.end(); ++iter)
    //     {
    //         vector<int> subarray{*iter};
    //         int subSum = *iter;
    //         if(subSum == k)
    //         {
    //             result.push_back(subarray);
    //         }                
    //         for(auto it = iter + 1; it != nums.end(); ++it)
    //         {
    //             subarray.push_back(*it);
    //             subSum += *it;
    //             if(subSum == k)
    //             {
    //                 result.push_back(subarray);
    //                 continue;
    //             }
    //         }                
    //     }

    //     return result.size();
    // }

    
    /**
     * 暴力求解， 不使用容器
     */
    // int subarraySum(vector<int> &nums, int k)
    // {
    //     int size = nums.size(), res = 0;
    //     for (int i = 0; i < size; ++i) {
    //         int sum = 0;
    //         for (int j = i; j < size; ++j) {
    //             sum += nums[j];
    //             res += sum == k ? 1 : 0;
    //         }
    //     }
    //     return res;
    // }

    /**
     *  前缀和+哈稀表优化
     */
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int preSum = 0;
        for(auto &i : nums)
        {
            preSum += i;
            if(mp.find(preSum - k) != mp.end()) count += mp[preSum - k];
            ++mp[preSum];
        }

        return count;
    }
};

int main()
{
    vector<int> nums{1,1,1};

    Solution solution;
    int k = solution.subarraySum(nums, 2);

    return 0;
}