/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
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
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int res = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] > 0) dp.push_back(dp[i - 1] + nums[i]);
            else dp.push_back(nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    int result = solution.maxSubArray(nums);

    return 0;
}
