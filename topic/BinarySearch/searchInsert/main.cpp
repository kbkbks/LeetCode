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
 public :
    // int searchInsert(vector<int>& nums, int target) {
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     int mid = (left + right) / 2;
    //     int ans;
    //     while (left < right) {
    //         if (nums[mid] == target) {
    //             return mid;
    //         }
    //         if (nums[mid] < target) {
    //             left = mid;
    //         }
    //         if (nums[mid] > target) {
    //             right = mid;
    //         }
    //         mid = (left + right) / 2;
    //         if (left + 1 == right && nums[mid] != target) {
    //             break;
    //         }
    //     }
    //     if (nums[left] > target) {
    //         ans = left;
    //     } else if (nums[left] < target && nums[right] > target) {
    //         ans = left + 1;
    //     } else if (nums[right] < target) {
    //         ans = right + 1;
    //     }
    //     return ans;
    // }

    // 官方代码，右界为大于等于
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int ans = n;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{1, 3, 5};
    int target = 1;
    Solution solution;
    int result = solution.searchInsert(nums, target);
    cout << result << endl;

    return 0;
}
