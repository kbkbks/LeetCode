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
    int countDigitOne(int n) {
        int cnt = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            cnt += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return cnt;
    }
};

int main() {
    int n = 10;
    Solution solution;
    int result = solution.countDigitOne(n);
    cout << result << endl;

    return 0;
}
