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
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid, ans = -1;
        while (left <= right) {
            // mid = left + right >> 1;
            mid = left + (right - left) / 2;
            if (nums[mid] == target) ans = mid;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution solution;
    int result = solution.search(nums, target);
    cout << result << endl;

    return 0;
}
