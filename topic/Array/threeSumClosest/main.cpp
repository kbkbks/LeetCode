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
    // // 暴力搜索
    // int threeSumClosest(vector<int>& nums, int target) {
    //     int ans = nums[0] + nums[1] + nums[2];
    //     for (int i = 0; i < nums.size(); ++i) {
    //         for (int j = i + 1; j < nums.size(); ++j) {
    //             for (int k = j + 1; k < nums.size(); ++k) {
    //                 if (abs(nums[i] + nums[j] + nums[k] - target) < abs(ans - target)) {
    //                     ans = nums[i] + nums[j] + nums[k];
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // 双指针
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e7;

        return ans;
    }
};

int main() {
    vector<int> nums{-1, 2, 1, -4};
    int target{1};
    Solution solution;
    int result = solution.threeSumClosest(nums, target);
    cout << result << endl;

    return 0;
}
