/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    int longestConsecutive(vector<int>& nums) {

    }
};

int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution solution;
    int result = solution.longestConsecutive(nums);
    cout << result << endl;

    return 0;
}
