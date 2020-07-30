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
    int balancedStringSplit(string s) {
        int ans = 0;
        int n = s.size();
        int banlance = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                ++banlance;
            } else if (s[i] == 'R') {
                --banlance;
            }
            if (!banlance) {
                ++ans;
            }
        }

        return ans;
    }
};

int main() {
    string s{"LLLLRRRR"};
    Solution solution;
    int result = solution.balancedStringSplit(s);
    cout << result << endl;
    return 0;
}
