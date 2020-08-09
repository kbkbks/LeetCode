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
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap.find(nums[i]) != hashmap.end()) return nums[i];
            hashmap[nums[i]]++;
        }
        return -1;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};

    Solution solution;
    int result = solution.findRepeatNumber(nums);

    return 0;
}
