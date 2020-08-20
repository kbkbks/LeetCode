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

bool cmp(string A, string B) {
    return A + B < B + A;
}

class Solution {
 public:
    string minNumber(vector<int>& nums) {
        string ans;
        vector<string> str;
        for (int i = 0; i < nums.size(); ++i) {
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), cmp);
        for (int i = 0; i < nums.size(); ++i) {
            ans += str[i];
        }
        return ans;
    }
};

int main() {
    vector<int> nums{10, 2};
    Solution solution;
    string result = solution.minNumber(nums);

    return 0;
}
