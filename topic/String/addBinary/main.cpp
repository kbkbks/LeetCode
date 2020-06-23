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
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size());
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans += (carry % 2) ? "1" : "0";
            carry /= 2;
        }
        if (carry) {
            ans += "1";
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    string a{"1010"};
    string b{"1011"};
    Solution solution;
    string result = solution.addBinary(a, b);

    return 0;
}
