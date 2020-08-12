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
     * 动态规划 
     */
    // int numWays(int n) {
    //     vector<int> dp(n + 5);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; ++i) {
    //         dp[i] = (dp[i - 1] + dp[i - 2]) % static_cast<int>(1e9 + 7);
    //     }

    //     return dp[n];
    // }

    /**
     * 滚动数组
     */
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main() {
    int n = 5;
    Solution solution;
    int result = solution.climbStairs(n);
    cout << result << endl;

    return 0;
}
