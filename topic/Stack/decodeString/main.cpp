/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 public:
    string getDigits(const string &s, string::iterator &ptr) {
        string ret = "";
        while (isdigit(*ptr)) {
            ret.push_back(*(ptr++));
        }
        return ret;
    }

    string getString(const vector<string> &v) {
        string ret;
        for (const auto &s : v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        string ans;
        // stack<string> st;
        // size_t ptr = 0;
        vector<string> stk;  // 用动态数组代替栈，便于遍历
        auto ptr = s.begin();

        while (ptr != s.end()) {
            char cur = *ptr;
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, *ptr++));
            } else {
                // 当前字符为右括号，开始出栈直到遇到左括号
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前sub对应的字符应该出现的次数
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t;
                string o = getString(sub);
                // 构造字符串
                while (repTime--) t += o;
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
};

int main() {
    string s{"3[a2[c]]"};
    Solution solution;
    string result = solution.decodeString(s);
    cout << result << endl;

    return 0;
}
