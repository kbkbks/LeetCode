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
    int f(int n, int m) {
        if (n == 1) return  0;
        int x = f(n - 1, m);
        return (m + x) % n;
    }

    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};

int main() {
    int n = 5, m = 3;
    Solution solution;
    int result = solution.lastRemaining(n, m);
    cout << result << endl;

    return 0;
}
