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
     * 常规方法（遍历整个数组）
     */
    vector<int> exchange(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                ans.push_back(nums[i]);
            } else {
                ans.insert(ans.begin(), nums[i]);
            }
        }

        return ans;
    }

    /**
     * 首尾双指针
     */
    vector<int> exchange(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            while (start < end && (nums[start] % 2 == 1)) {
                ++start;
            }
            while (start < end && (nums[end] % 2 == 0)) {
                --end;
            }
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
        }

        return nums;
    }

    // /**
    //  * 快慢指针，双指针
    //  */
    // vector<int> exchange(vector<int>& nums) {
    //     int low = 0, fast = 0;
    //     while (fast < nums.size()) {
    //         if (nums[fast] % 2 == 1) {
    //             swap(nums[low], nums[fast]);
    //             ++low;
    //         }
    //         ++fast;
    //     }

    //     return nums;
    // }

};

int main() {
    vector<int> nums{1, 2, 3, 4};
    Solution solution;
    vector<int> result = solution.exchange(nums);

    return 0;
}
