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
     * 哈希映射法
     */
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            hashmap[nums[i]]++;
            if (hashmap[nums[i]] > (n / 2)) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }

    // /**
    //  * 摩尔投票
    //  */
    // int majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     int count = 0;
    //     int cur = 0;
    //     for (int i = 0; i < n; ++i) {
    //         if (count == 0) {
    //             cur = nums[i];
    //         }
    //         if (cur == nums[i]) {
    //             ++count;
    //         } else {
    //             --count;
    //         }
    //     }
    //     return cur;
    // }
};

int main() {
    vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
    Solution solution;
    int result = solution.majorityElement(nums);

    return 0;
}
