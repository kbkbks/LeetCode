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
    /**
     * 两次二分查找，确定上下界
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int> {-1, -1};
        int i = 0, j = nums.size() - 1;
        // 搜索右边界
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] <= target) i = mid + 1;
            if (nums[mid] > target) j = mid - 1;
        }
        int right = i;
        // 数组中无target，提前返回
        if (j < 0 || nums[j] != target) return vector<int>{-1, -1};
        // 搜索左边界
        i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] < target) i = mid + 1;
            if (nums[mid] >= target) j = mid - 1;
        }
        int left = j;

        return vector<int>{left + 1, right - 1};
    }
};

int main() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution solution;
    vector<int> result = solution.searchRange(nums, target);

    return 0;
}
