/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
 public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<vector<int>> f(prices.size(), vector<int>(3));
        f[0][0] = - prices[0];
        f[0][1] = 0;
        f[0][2] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }

        return max(f[prices.size() - 1][1], f[prices.size() - 1][2]);
    }
};

int main() {
    vector<int> prices{1, 2, 3, 0, 2};
    Solution solution;
    int result = solution.maxProfit(prices);
    cout << result << endl;

    return 0;
}
