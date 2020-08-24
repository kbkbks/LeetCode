/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
 public:
    /**
     * 常规模拟法
     */
    bool isNumber(string s) {
        // 除去字符串前后空格
        int i = s.find_first_not_of(' ');
        if (i == string::npos) return false;
        int j = s.find_last_not_of(' ');
        s = s.substr(i, j - i + 1);

        // 根据e划分指数和底数
        int e = s.find('e');
        if (e == string::npos && s.find('E')) e = s.find('E');

        // 指数为空，判断底数
        if (e == string::npos) return judgeP(s);

        // 指数不为空，判断指数和底数
        else return judgeP(s.substr(0, e)) && judgeS(s.substr(e + 1));
    }

    // 判断底数是否合法
    bool judgeP(string s) {
        bool res = false, point = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (i != 0) return false;    // 符号位不在第一位
            } else if (s[i] == '.') {
                if (point == true) return false;    // 有多个小数点
                point = true;
            } else if (s[i] < '0' || s[i] > '9') return false;  // 非纯字符
            else res = true;
        }
        return res;
    }

    // 判断指数是否合法
    bool judgeS(string s) {
        bool res = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (i != 0) return false;   // 符号位不在第一位
            } else if (s[i] < '0' || s[i] > '9') return false;   // 非纯字符
            else res = true;
        }
        return res;
    }

    /**
     * 自动机方法（未写）
     */
};

int main() {
    string s{"-1E-16"};
    Solution solution;
    bool result = solution.isNumber(s);

    return 0;
}
