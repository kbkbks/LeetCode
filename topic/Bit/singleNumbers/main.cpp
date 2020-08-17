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
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
 public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums) {
            ret ^= n;
        }
        int div = 1;
        while ((div & ret) == 0) {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int n : nums) {
            if (div & n) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return vector<int>{a, b};
    }
};

int main() {
    vector<int> nums{4, 1, 4, 6};
    Solution solution;
    vector<int> result = solution.singleNumbers(nums);

    return 0;
}
