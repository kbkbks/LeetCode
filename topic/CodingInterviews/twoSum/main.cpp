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
     * （首尾）双指针
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int> ans;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                break;
            } else if (nums[i] + nums[j] > target) {
                --j;
            } else if (nums[i] + nums[j] < target) {
                ++i;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    return 0;
}
