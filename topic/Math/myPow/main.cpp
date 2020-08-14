/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    double myPow(double x, int n) {
        double res = 1;
        if (n == 0) return 1;
        if (x == 0.0) return 0;
        if (x == 1.0) return 1.0;

        long num = n;
        if (n < 0) {
            num = -num;
            x = 1 / x;
        }

        while (num) {
            if (num & 1) res *= x;
            x *= x;
            num >>= 1;
        }

        return res;
    }
};

int main() {
    double x = 2.00000;
    int n = 10;
    Solution solution;
    double result = solution.myPow(x, n);
    cout << result << endl;

    return 0;
}
