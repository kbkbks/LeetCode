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
    // 逻辑运算符短路性质
    int sumNums(int n) {
        n && (n += sumNums(n - 1));

        return n;
    }
};

int main() {
    int n = 5;
    Solution solution;
    int result = solution.sumNums(n);
    cout << result << endl;

    return 0;
}
