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
     * 常规解法
     */
    vector<int> printNumbers(int n) {
        if (n == 0) return {};
        vector<int> ans;
        int maxValue = pow(10, n) - 1;
        for (int i = 1; i < maxValue + 1; ++i) {
            ans.push_back(i);
        }

        return ans;
    }
    
    /**
     * 常规解法递归版
     */
    // vector<int> Numbers(vector<int> ans, int n) {
    //     if ( n < 0) return {};
    //     ans = Numbers(ans, n - 1);
    //     for (int i = pow(10, n); i < pow(10, n) * 9 + pow(10, n); ++i) {
    //         ans.push_back(i);
    //     }
    //     return ans;
    // }

    // vector<int> printNumbers(int n) {
    //     vector<int> ans;
    //     return Numbers(ans, n - 1);
    // }


};

int main() {
    int n = 3;
    Solution solution;
    vector<int> result = solution.printNumbers(n);

    return 0;
}
