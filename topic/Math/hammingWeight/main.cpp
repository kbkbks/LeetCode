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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n = n & (n - 1);
            ++res;
        }
        return res;
    }
};

int main() {
    uint32_t n = 00000000000000000000000000001011;
    Solution solution;
    int result = solution.hammingWeight(n);
    cout << result << endl;

    return 0;
}
