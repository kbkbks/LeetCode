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
     * 归并排序
     */
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }

    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        int cnt = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                cnt += (j - (mid + 1));
            } else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            cnt += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return cnt;
    }
};

int main() {
    vector<int> nums{7, 5, 6, 4};
    Solution solution;
    int result = solution.reversePairs(nums);

    return 0;
}
