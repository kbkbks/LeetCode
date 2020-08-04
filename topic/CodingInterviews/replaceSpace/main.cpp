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

class Solution {
 public:
    string replaceSpace(string s) {
        string ans = "";
        for (auto &c : s) {
            if (c == ' ') {
                ans.append("%20");
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }

    // /**
    //  * 调用stirng.replace()
    //  */
    // string replaceSpace(string s) {
    //     for (int i = 0; i < s.length(); ++i) {
    //         if (s[i] == ' ') {
    //             s.replace(i, 1, "%20");
    //         }
    //     }

    //     return s;
    // }
};

int main() {
    string s = "We are happy.";

    Solution solution;
    string result = solution.replaceSpace(s);

    return 0;
}
