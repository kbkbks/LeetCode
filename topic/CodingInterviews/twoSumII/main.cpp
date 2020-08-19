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
    vector<double> twoSum(int n) {
        vector<double> res;
        vector<vector<double>> dp(n + 1, vector<double>(n * 6 + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= i * 6; ++j) {
                if (i == 1) {
                    dp[i][j] = 1.0;
                    continue;
                }
                for (int k = 1; k <= 6; ++k) {
                    if (j - k >= i - 1) dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for (int i = n; i <= n * 6; ++i) {
            res.push_back(dp[n][i] * pow(1.0 / 6.0, n));
        }

        return res;
    }
};

int main() {
    int n = 9;
    Solution solution;
    vector<double> result = solution.twoSum(n);

    return 0;
}
