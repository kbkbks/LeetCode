/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
    /**
     * 常规方法
     */
    int myAtoi(string str) {
        int res = 0;
        int i = 0;
        int flag = 1;
        while (str[i] == ' ') i++;
        if (str[i] == '-') {
            flag = -1;
            ++i;
        } else if (str[i] == '+') {
            flag = 1;
            ++i;
        }
        if (str[i] == '+' || str[i] == '-') return 0;
        while (i < str.size() && isdigit(str[i])) {
            int r = str[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) {
                return (flag > 0) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + r;
            ++i;
        }
        return (flag > 0) ? res : -res;
    }

    /**
     * 自动机（未写）
     */
};

int main() {
    string s{"-44"};
    Solution solution;
    int result = solution.myAtoi(s);

    return 0;
}
