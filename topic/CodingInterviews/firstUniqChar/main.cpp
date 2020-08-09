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
    char firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.length(); ++i) {
            hashmap[s[i]]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (hashmap[s[i]] == 1) return s[i];
        }
        return ' ';
    }
};

int main() {
    string s{"abaccdeff"};

    Solution solution;
    char result = solution.firstUniqChar(s);

    return 0;
}
