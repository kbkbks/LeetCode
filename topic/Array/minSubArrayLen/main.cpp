/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
 public:
    // // 暴力求解
    // int minSubArrayLen(int s, vector<int>& nums) {
    //     int ans = INT32_MAX;
    //     if (!nums.size()) {
    //         return 0;
    //     }

    //     for (int i = 0; i < nums.size(); ++i) {
    //         int pre = 0;
    //         for (int j = i; j < nums.size(); ++j) {
    //             pre += nums[j];
    //             if (pre >= s) {
    //                 if (j - i + 1 < ans) {
    //                     ans = j - i + 1;
    //                 }
    //                 break;
    //             }
    //         }
    //     }

    //     return ans == INT32_MAX ? 0 : ans;
    // }

    // // 前缀和+二分搜索
    // int minSubArrayLen(int s, vector<int>& nums) {
    //     int ans = INT32_MAX;
    //     if (!nums.size()) {
    //         return 0;
    //     }
    //     vector<int> preSum(nums.size() + 1, 0);
    //     for (int i = 1; i <= nums.size(); ++i) {
    //         preSum[i] = preSum[i - 1] + nums[i - 1];
    //     }

    //     for (int i = 1; i <= nums.size(); ++i) {
    //         int target = s + preSum[i - 1];
    //         auto bound = lower_bound(preSum.begin(), preSum.end(), target);
    //         if (bound != preSum.end()) {
    //             ans = min(ans, static_cast<int>(bound - preSum.begin() - (i - 1)));
    //         }
    //     }
    //     return ans == INT32_MAX ? 0 : ans;
    // }

    // 双指针，滑动窗口法
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT32_MAX;
        if (!nums.size()) {
            return 0;
        }
        int start = 0;
        int end = 0;
        int slideSum = 0;
        while (end < nums.size()) {
            slideSum += nums[end];
            while (slideSum >= s) {
                ans = min(ans, end - start + 1);
                slideSum -= nums[start];
                ++start;
            }
            ++end;
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};

int main() {
    int s = 7;
    vector<int> nums{2, 3, 1, 2, 4, 3};
    Solution solution;
    int result = solution.minSubArrayLen(s, nums);
    cout << result << endl;

    return 0;
}
