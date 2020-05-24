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
    // 使用标准库的sort函数，但时间复杂度为O(nlogn), 不满足题目要求log(m + n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if (nums1.size() % 2 != 0) {
            ans = nums1[nums1.size() / 2];
        } else {
            ans = static_cast<double>(nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
        }

        return ans;
    }
};

int main() {
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};

    Solution solution;
    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    return 0;
}
