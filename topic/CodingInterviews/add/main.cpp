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
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned int)(a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};

int main() {
    int a = 9, b = -8;
    Solution solution;
    int result = solution.add(a, b);

    return 0;
}
