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
    string reverseWords(string s) {
        string tmp;
        string res;
        stringstream ss(s);
        vector<string> vecStr;
        while (ss >> tmp) {
            vecStr.push_back(tmp);
        }
        reverse(vecStr.begin(), vecStr.end());
        if (!vecStr.empty()) {
            for (int i = 0; i < vecStr.size() - 1; ++i) {
                res += vecStr[i] + " ";
            }
            res += vecStr[vecStr.size() - 1];
        }
        return res;
    }
};

int main() {
    string s{"the sky is blue"};
    Solution solution;
    string result = solution.reverseWords(s);

    return 0;
}
