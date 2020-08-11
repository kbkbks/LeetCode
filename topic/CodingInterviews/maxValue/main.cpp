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
    int maxValue(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < c; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < r; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[r - 1][c - 1];
    }
};

int main() {
    vector<vector<int>> nums{
       {1, 3, 1},
       {1, 5, 1},
       {4, 2, 1}
    };

    Solution solution;
    int result = solution.maxValue(nums);

    return 0;
}
