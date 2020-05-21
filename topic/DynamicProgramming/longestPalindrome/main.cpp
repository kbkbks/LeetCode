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
    // bool checkPalindrome(const string& s, int low, int high) {
    //     for (int i = low, j = high; i < j; ++i, --j) {
    //         if (s[i] != s[j]) return false;
    //     }

    //     return true;
    // }

    // // 贪婪算法
    // string longestPalindrome(string s) {
    //     string substr;
    //     for (int i = 0; i < s.size(); ++i) {
    //         for (int j = 0; j < i + 1; ++j) {
    //             if (checkPalindrome(s, j, j + s.size() - i - 1)) {
    //                 substr = s.substr(j, s.size() - i);
    //                 return substr;
    //             }
    //         }
    //     }

    //     return substr;
    // }

    // 动态规划
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }

        return ans;
    }
};

int main() {
    string str{"babad"};
    Solution solution;
    string substr = solution.longestPalindrome(str);
    cout << substr << endl;

    return 0;
}
