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
#include <sstream>
#include <stack>

using namespace std;

class Solution {
 public:
    vector<string> res;

    void dfs(int x, string& s) {
        if (x == s.size() - 1) {
            res.push_back(s);
            return;
        }

        unordered_set<char> hashset;
        for (int i = x; i < s.size(); ++i) {
            if (hashset.find(s[i]) != hashset.end()) continue;
            hashset.insert(s[i]);
            swap(s[x], s[i]);
            dfs(x + 1, s);
            swap(s[x], s[i]);
        }
        return;
    }

    vector<string> permutation(string s) {
        dfs(0, s);
        return res;
    }
};

int main() {
    string s = {"abc"};
    Solution solution;
    vector<string> result = solution.permutation(s);

    return 0;
}
