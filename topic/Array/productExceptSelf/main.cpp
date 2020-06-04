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
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> ans(nums.size(), 1);

    //     for (int i = 0; i < nums.size(); ++i) {
    //         for (int j = 0; j < nums.size(); ++j) {
    //             if (j == i) continue;
    //             ans[i] *= nums[j];
    //         }
    //     }

    //     return ans;
    // }

    // // 左右乘积列表
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int length = nums.size();
    //     // 左右两侧的乘积列表
    //     vector<int> L(length, 1);
    //     vector<int> R(length, 1);
    //     vector<int> ans(length, 1);

    //     // 计算左右两侧乘积列表LR的值
    //     for (int i = 1; i < length; ++i) {
    //         L[i] = L[i - 1] * nums[i - 1];
    //     }
    //     for (int i = length - 2; i >= 0; --i) {
    //         R[i] = R[i + 1] * nums[i + 1];
    //     }
    //     // 左右两边乘积则为输出
    //     for (int i = 0; i < length; ++i) {
    //         ans[i] = L[i] * R[i];
    //     }

    //     return ans;
    // }

    // 空间复杂度O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> ans(length, 1);
        // ans表示左侧所有元素的乘积
        for (int i = 1; i < length; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // R为右侧所有元素的乘积
        int R = 1;
        for (int i = length - 1; i >= 0; --i) {
            // 左右两边乘积则为输出
            ans[i] = ans[i] * R;
            // 动态更新下一个R
            R *= nums[i];
        }

        return ans;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4};
    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);

    return 0;
}
