/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
    int integerBreak(int n) {
        int ans;
        int les = n / 3, res = n % 3;
        if (n == 2) return 1;
        if (n == 3) return 2;

        if (res == 0) {
            ans = pow(3, les);
        } else if (res == 1) {
            ans = pow(3, les - 1) * 2 * 2;
        } else if (res == 2) {
            ans = pow(3, les) * 2;
        }
        return ans;
    }
};

int main() {
    int n = 10;
    Solution solution;
    int result = solution.integerBreak(n);
    cout << result << endl;

    return 0;
}
