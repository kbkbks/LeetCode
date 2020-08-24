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
     * 位和法
     */
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (auto n : nums) {
                // 统计每一位的数字和
                if (n & (1 << i)) cnt++;
            }
            // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
            if (cnt % 3 == 1) res ^= (1 << i);
        }
        return res;
    }

    // /**
    //  * 位和法
    //  */
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int, int> hashmap;
    //     int res;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         hashmap[nums[i]]++;
    //     }
    //     for (auto iter = hashmap.begin(); iter != hashmap.end(); ++iter) {
    //         if (iter->second == 1) {
    //             res = iter->first;
    //             break;
    //         }
    //     }
    //     return res;
    // }
};

int main() {
    vector<int> nums{3, 4, 3, 3};
    Solution solution;
    int result = solution.singleNumber(nums);

    return 0;
}
