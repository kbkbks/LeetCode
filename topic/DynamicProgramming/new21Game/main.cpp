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
    // // 普通动态规划法
    // double new21Game(int N, int K, int W) {
    //     if (K == 0) {
    //         return 1.0;
    //     }

    //     vector<double> dp(K + W + 1);
    //     for (int i = K; i <= N && i < K + W; ++i) {
    //         dp[i] = 1.0;
    //     }
    //     for (int i = K - 1; i >= 0; --i) {
    //         for (int j = 1; j <= W; j++) {
    //             dp[i] += dp[i + j] / W;
    //         }
    //     }

    //     return dp[0];
    // }

    // 差分动态规划法
    double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1.0;
        }

        vector<double> dp(K + W);
        for (int i = K; i <= N && i < K + W; ++i) {
            dp[i] = 1.0;
        }
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; --i) {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }

        return dp[0];
    }
};

int main() {
    int N = 27, K = 17, W = 10;
    Solution solution;
    double result = solution.new21Game(N, K, W);
    cout << result << endl;

    return 0;
}
