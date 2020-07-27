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
    // 动态规划
    bool isSubsequence(string s, string t) {
        int n = t.size();
        vector<int> f(n + 2, 0);
        int inc(0);
        for (int i = 0; i <= t.size(); ++i) {
            if (t[i] == s[inc]) {
                f[i + 1] = f[i] + 1;
                ++inc;
                if (inc == s.size()) return true;
            } else {
                f[i + 1] = f[i];
            }
        }

        return f[n] == s.size() ? true : false;
    }
};

int main() {
    string s{"abc"};
    string t{"ahbgdc"};
    Solution solution;
    bool result = solution.isSubsequence(s, t);
    cout << result << endl;

    return 0;
}
