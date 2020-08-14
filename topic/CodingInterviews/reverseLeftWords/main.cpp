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
    string reverseLeftWords(string s, int n) {
        string doublestr = s + s;
        return doublestr.substr(n, s.size());
    }
};

int main() {
    string s{"abcdefg"};
    int n = 2;
    Solution solution;
    string result = solution.reverseLeftWords(s, n);

    return 0;
}
