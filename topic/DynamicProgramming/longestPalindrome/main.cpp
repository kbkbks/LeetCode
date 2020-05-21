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
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }

        return true;
    }

    // 贪婪算法
    string longestPalindrome(string s) {
        string substr;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (checkPalindrome(s, j, j + s.size() - i - 1)) {
                    substr = s.substr(j, s.size() - i);
                    return substr;
                }
            }
        }

        return substr;
    }
};

int main() {
    string str{"cbbd"};
    Solution solution;
    string substr = solution.longestPalindrome(str);
    cout << substr << endl;

    return 0;
}
