/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    // /**
    //  * 暴力破解
    //  */
    // int nthUglyNumber(int n) {
    //     vector<int> vec;
    //     for (long long a = 1; a < INT_MAX; a = a * 2) {
    //         for (long long b = a; b < INT_MAX; b = b * 3) {
    //             for (long long c = b; c < INT_MAX; c = c * 5) {
    //                 vec.push_back(c);
    //             }
    //         }
    //     }
    //     sort(vec.begin(), vec.end());
    //     return vec[n - 1];
    // }

    // /**
    //  * 优先队列法（小顶堆）
    //  */
    // int nthUglyNumber(int n) {
    //     priority_queue<long long, vector<long long>, greater<long long> > pq;
    //     long long ans = 1;
    //     for (int i = 1 ;i < n; ++i) {
    //         pq.push(ans * 2);
    //         pq.push(ans * 3);
    //         pq.push(ans * 5);
    //         ans = pq.top();
    //         pq.pop();
    //         while (!pq.empty() && pq.top() == ans) {
    //             pq.pop();
    //         }
    //     }
    //     return ans;
    // }

    /**
     * 动态规划
     */
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(min(2 * dp[p2], 3 * dp[p3]), 5 * dp[p5]);
            if (dp[i] == 2 * dp[p2]) p2++;
            if (dp[i] == 3 * dp[p3]) p3++;
            if (dp[i] == 5 * dp[p5]) p5++;
        }
        return dp[n - 1];
    }
};

int main() {
    int n = 10;
    Solution solution;
    double result = solution.nthUglyNumber(n);
    cout << result << endl;

    return 0;
}
