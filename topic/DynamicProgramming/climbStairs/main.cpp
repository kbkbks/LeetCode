/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
 public:
    // // 动态规划
    // int rob(vector<int>& nums) {
    //     if (nums.empty()) {
    //         return 0;
    //     }
    //     int n = nums.size();
    //     if (n == 1) {
    //         return nums[0];
    //     }
    //     vector<int> dp(n, 0);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);
    //     for (int i = 2; i < n; ++i) {
    //         dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    //     }
    //     return dp[n - 1];
    // }

    // 动态规划＋滚动数组
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};

int main() {
    vector<int> nums{2, 7, 9, 3, 1};
    Solution solution;
    int result = solution.rob(nums);
    cout << result << endl;

    return 0;
}
