/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
 public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }

        return true;
    }

    // // 暴力求解（超时）
    // bool validPalindrome(string s) {
    //     int low = 0, high = s.size() - 1;
    //     if (checkPalindrome(s, low, high)) return true;

    //     for (int i = 0; i < s.size(); ++i) {
    //         string scp = s;
    //         string subStr = scp.erase(i, 1);
    //         int low = 0, high = subStr.size() - 1;
    //         if (checkPalindrome(subStr, low, high)) return true;
    //     }
    //     return false;
    // }

    // 贪婪算法
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }

        return true;
    }
};

int main() {
    string  str{"abca"};
    Solution solution;
    bool status = solution.validPalindrome(str);
    cout << status << endl;

    return 0;
}
