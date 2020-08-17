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
     * 常规DP
     */
    int translateNum(int num) {
        string str = to_string(num);
        vector<int> dp(str.size() + 5, 0);
        dp[0] = 1;
        string p = str.substr(0, 2);
        if (p <= "25" && p >= "10") {
            dp[1] = dp[0] + 1;
        } else {
            dp[1] = dp[0];
        }

        for (int i = 2; i < str.size() ; ++i) {
            string pre = str.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[str.size() - 1];
    }

    // /**
    //  * 滚动数组优化
    //  */
    // int translateNum(int num) {
    //     string str = to_string(num);
    //     int p = 0, q = 0, r = 1;
    //     for (int i = 0; i < str.size(); ++i) {
    //         p = q;
    //         q = r;
    //         r = 0;
    //         r += q;
    //         if (i == 0) continue;
    //         string pre = str.substr(i - 1, 2);
    //         if (pre <= "25" && pre >= "10") {
    //             r += p;
    //         }
    //     }
    //     return r;
    // }
};

int main() {
    int num = 12258;
    Solution solution;
    int result = solution.translateNum(num);

    return 0;
}
