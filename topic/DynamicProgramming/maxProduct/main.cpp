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
    // // 暴力求解
    // int maxProduct(vector<int>& nums) {
    //     int maxProduct = nums[0];
    //     int maxLength = nums.size();
    //     for (int i = 0; i < maxLength; ++i) {
    //         int Product = nums[i];
    //         if (Product > maxProduct) maxProduct = Product;
    //         for (int j = i + 1; j < maxLength; ++j) {
    //             Product *= nums[j];
    //             if (Product > maxProduct) maxProduct = Product;
    //         }
    //     }

    //     return maxProduct;
    // }

    // 动态规划法
    int maxProduct(vector<int>& nums) {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(minF[i - 1] * nums[i], nums[i]));
            minF[i] = min(maxF[i - 1] * nums[i], min(minF[i - 1] * nums[i], nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

int main() {
    vector<int> nums{-4, -3};

    Solution solution;
    int maxProduct = solution.maxProduct(nums);
    cout << maxProduct << endl;
}
