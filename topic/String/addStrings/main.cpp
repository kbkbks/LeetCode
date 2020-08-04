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
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        int add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int a = i >= 0 ? num1[i] - '0' : 0;
            int b = j >= 0 ? num2[j] - '0' : 0;
            int result = (a + b + add) % 10;
            ans.push_back('0' + result);
            add = (a + b + add) / 10;
            --i;
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string a{"0"};
    string b{"0"};
    Solution solution;
    string result = solution.addStrings(a, b);

    return 0;
}
