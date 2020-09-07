/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

// 最长递增子序列
int main() {
    vector<int> nums = {4, 2, 3, 1, 5};
    int res = 0;
    vector<int> dp(nums.size());     // 以i结尾的最长递增子序列长度
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
        int cnt = 1;
        for (int j = i - 1; j >= 0;  j--) {
            if (nums[i] > nums[j]) {
                cnt = max(cnt, dp[j] + 1);
            }
        }
        dp[i] = cnt;
    }
    for (int i = 0; i < dp.size(); ++i) {
        res = max(res, dp[i]);
    }

    cout << res << endl;
    
    return 0;
}
