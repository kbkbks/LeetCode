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
    // /**
    //  * 暴力求解
    //  */
    // int maxProfit(vector<int>& prices) {
    //     int res = 0;
    //     for (int i = 0; i < prices.size() - 1; ++i) {
    //         for (int j = i + 1; j < prices.size(); ++j) {
    //             if (prices[j] - prices[i] > 0) {
    //                 res = max(res, prices[j] - prices[i]);
    //             }
    //         }
    //     }
    //     return res;
    // }

    /**
     * 最低价格法（类似于动态规划）
     */
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = INT32_MAX;
        for (int price : prices) {
            res = max(res, price - minPrice);
            minPrice = min(minPrice, price);
        }

        return res;
    }
};

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution solution;
    int result = solution.maxProfit(prices);
    cout << result << endl;

    return 0;
}
