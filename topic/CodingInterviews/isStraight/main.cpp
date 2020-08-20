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
     * 自己写的基于排序方法
     */
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> flag;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == 0) {
                flag.push_back(true);
                continue;
            }

            if (nums[i + 1] == nums[i]) return false;

            if (nums[i + 1] != nums[i] + 1) {
                while (!flag.empty()) {
                    flag.pop_back();
                    nums[i]++;
                    if (nums[i + 1] == nums[i] + 1) break;
                }
                if (nums[i + 1] != nums[i] + 1) return false;
            }
        }

        return true;
    }

    // /**
    //  * 基于HashSet方法
    //  */
    // bool isStraight(vector<int>& nums) {
    //     unordered_set<int> hashset;
    //     int maxValue = 0, minValue = 14;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         if (nums[i] == 0) continue;
    //         maxValue = max(maxValue, nums[i]);
    //         minValue = min(minValue, nums[i]);
    //         if (hashset.count(nums[i])) return false;
    //         hashset.insert(nums[i]);
    //     }
    //     return maxValue - minValue < 5;
    // }
};

int main() {
    vector<int> nums{0, 0, 1, 2, 5};
    Solution solution;
    bool result = solution.isStraight(nums);

    return 0;
}
