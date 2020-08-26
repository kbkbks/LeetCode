/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
    /**
     * 动态规划（还有一个lambda表达式）
     */
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto match = [&](int i, int j) {
            if (i == 0) return false;
            if (p[j - 1] == '.') return true;
            return s[i - 1] == p[j - 1];
        };

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (match(i, j - 1)) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    if (match(i, j)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "aab";
    string p = "c*a*b";
    Solution solution;
    bool result = solution.isMatch(s, p);

    return 0;
}
