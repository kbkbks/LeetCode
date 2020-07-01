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
    // // 暴力搜索(超时)
    // int findLength(vector<int>& A, vector<int>& B) {
    //     int ans = 0;
    //     for (int i = 0; i < A.size(); ++i) {
    //         for (int j = 0; j < B.size(); ++j) {
    //             int k = 0;
    //             while (A[i + k] == B[j + k]) {
    //                 ++k;
    //             }
    //             ans = max(ans, k);
    //         }
    //     }
    //     return ans;
    // }

    // // 动态规划
    // int findLength(vector<int>& A, vector<int>& B) {
    //     int ans = 0;
    //     int n = A.size(), m = B.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //     for (int i = n - 1; i >= 0; --i) {
    //         for (int j = m - 1; j >= 0; --j) {
    //             if (A[i] == B[j]) {
    //                 dp[i][j] = dp[i + 1][j + 1] + 1;
    //             } else {
    //                 dp[i][j] = 0;
    //             }
    //             ans = max(ans, dp[i][j]);
    //         }
    //     }
    //     return ans;
    // }

    // 滑动窗口
    int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
        int ret = 0;
        int k = 0;
        for (int i = 0; i < len; ++i) {
            if (A[addA + i] == B[addB + i]) {
                ++k;
            } else {
                k = 0;
            }
            ret = max(ret, k);
        }
        return ret;
    }

    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0;
        int n = A.size(), m = B.size();
        for (int i = 0; i < n; ++i) {
            int len = min(n - i, m);
            int maxlen = maxLength(A, B, i, 0, len);
            ans = max(ans, maxlen);
        }
        for (int i = 0; i < m; ++i) {
            int len = min(m - i, n);
            int maxlen = maxLength(A, B, 0, i, len);
            ans = max(ans, maxlen);
        }
        return ans;
    }
};

int main() {
    vector<int> A{1, 2, 3, 2, 1};
    vector<int> B{3, 2, 1, 4, 7};

    Solution solution;
    int result = solution.findLength(A, B);
    cout << result << endl;

    return 0;
}
