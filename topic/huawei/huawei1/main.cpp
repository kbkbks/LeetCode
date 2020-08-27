/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

// Interview1

// class Solution{
//  public:

// };

int main() {
    vector<unsigned int> nums{1, 2};
    vector<unsigned int> res(nums.size());
    vector<vector<unsigned int>> vec(nums.size(), vector<unsigned int>(2));
    for (int i = 0; i < nums.size(); ++i) {
        unsigned int cnt = 0;
        while (nums[i] != 0) {
            if (cnt == 0) {
                vec[i][0] = nums[i] & 1;
                nums[i] >>= 1;
                vec[i][1] = nums[i] & 1;
                nums[i] >>= 1;
            } else {
                res[i] += (nums[i] & 1) << (2 * (cnt - 1) + 1);
                nums[i] = nums[i] >> 1;
                res[i] += (nums[i] & 1) << (2 * (cnt - 1));
                nums[i] = nums[i] >> 1;
            }
            cnt++;
        }        
    }

    for (int i = 1; i < nums.size(); ++i) {
        res[i] += vec[i - 1][0] << 31;
        res[i] += vec[i - 1][1] << 30;
    }
    res[0] += vec[nums.size() - 1][0] << 31;
    res[0] += vec[nums.size() - 1][1] << 30;

    return 0;
}
