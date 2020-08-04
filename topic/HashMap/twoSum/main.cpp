/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    /**
     *  双指针法，复杂度O(N)
     */
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> ans;
    //     vector<int> index(nums);
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0, j = n - 1; i < j;) {
    //         if (nums[i] + nums[j] > target) {
    //             --j;
    //         } else if (nums[i] + nums[j] < target) {
    //             ++i;
    //         } else if (nums[i] + nums[j] == target) {
    //             for (int k = 0; k < n; ++k) {
    //                 if (i < n && index[k] == nums[i]) {
    //                     ans.push_back(k);
    //                     i = n;
    //                 } else if (j < n && index[k] == nums[j]) {
    //                     ans.push_back(k);
    //                     j = n;
    //                 }
    //                 if (i == n && j == n) break;
    //             }

    //             break;
    //         }
    //     }

    //     return ans;
    // }

    /**
     *  哈希法，复杂度O(N)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap.find(target - nums[i]) != hashmap.end() && hashmap[target - nums[i]] != i) {
                ans.push_back(hashmap[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            hashmap[nums[i]] = i;
        }
        return ans;
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> k = solution.twoSum(nums, target);

    return 0;
}
