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
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums{3, 4, 5, 1, 2};
    Solution solution;
    int result = solution.findMin(nums);
    cout << result << endl;

    return 0;
}
