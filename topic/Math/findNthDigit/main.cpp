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
    int findNthDigit(int n) {
        // 计算数字位数
        long base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            ++digits;
        }

        // 计算真实数字
        int idx = n % digits;
        if (idx == 0) idx = digits;
        long number = 1;
        for (int i = 1; i < digits; ++i) {
            number *= 10;
        }
        number += (idx == digits) ? n / digits - 1 : n / digits;

        // 从真实数字中获得位数
        for (int i = idx; i < digits; ++i) {
            number /= 10;
        }
        return number % 10;
    }
};

int main() {
    int n = 11;
    Solution solution;
    int result = solution.findNthDigit(n);
    cout << result << endl;

    return 0;
}
