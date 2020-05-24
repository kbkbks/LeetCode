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
    // // 使用标准库的sort函数，但时间复杂度为O(nlogn), 不满足题目要求log(m + n)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     double ans;
    //     nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    //     sort(nums1.begin(), nums1.end());
    //     if (nums1.size() % 2 != 0) {
    //         ans = nums1[nums1.size() / 2];
    //     } else {
    //         ans = static_cast<double>(nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
    //     }

    //     return ans;
    // }

    // 二分查找
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 != 0) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, totalLength / 2) +
             getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
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
