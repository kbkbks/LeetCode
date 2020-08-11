/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
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
    /**
     * vector
     */
    // int fib(int n) {
    //     vector<int> f;
    //     f.push_back(0);
    //     f.push_back(1);
    //     for (int i = 2; i <= n; ++i) {
    //         f.push_back((f[i - 1] + f[i - 2]) % static_cast<int>(1e9 + 7));
    //     }

    //     return f[n];
    // }

    /**
     * 压缩动态空间
     */
    int fib(int n) {
        int array[2]{0, 1};
        for (int i = 2; i <= n; ++i) {
            array[i & 1] = (array[0] + array[1]) % static_cast<int>(1e9 + 7);
        }

        return array[n & 1];
    }
};

int main() {
    int n = 5;
    Solution solution;
    int result = solution.fib(n);

    return 0;
}
