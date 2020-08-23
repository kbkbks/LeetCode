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
    /**
     *  二分法
     */
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid) left = mid + 1;
            if (nums[mid] != mid) right = mid - 1;
        }

        return left;
    }

    // /**
    //  *  暴力破解（求快）
    //  */
    // int missingNumber(vector<int>& nums) {
    //     for (int i = 0; i < nums.size(); ++i) {
    //         if (nums[i] != i) {
    //             return i;
    //         }
    //     }
    //     return nums.size();
    // }
};

int main() {
    vector<int> nums{0, 1, 3};
    Solution solution;
    int result = solution.missingNumber(nums);

    return 0;
}
