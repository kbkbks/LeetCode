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
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, 1);
        int left = 1;

        for (int i = 0; i < n; ++i) {
            res[i] = left;
            left *= a[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= a[i];
        }

        return res;
    }
};

int main() {
    vector<int> a{2, 7, 11, 15};
    Solution solution;
    vector<int> result = solution.constructArr(a);

    return 0;
}
