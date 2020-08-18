/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    /**
     * 普通hash_set，时间复杂度O(n^2)
     */
    // int lengthOfLongestSubstring(string s) {
    //     if (s.size() == 0) return 0;

    //     int res = 0;
    //     unordered_set<char> hashset;
    //     for (int i = 0; i < s.size(); ++i) {
    //         int len = 1;
    //         hashset.clear();
    //         hashset.insert(s[i]);
    //         for (int j = i + 1; j < s.size(); ++j) {
    //             if (hashset.count(s[j])) break;
    //             else {
    //                 hashset.insert(s[j]);
    //                 ++len;
    //             }
    //         }
    //         res = max(len, res);
    //     }

    //     return res;
    // }

    /**
     * 双指针hash_set，时间复杂度O(n)
     */
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        int res = 0;
        unordered_set<char> hashset;
        int left = 0;
        for  (int right = 0; right < s.size(); ++right) {
            while (hashset.find(s[right]) != hashset.end()) {
                hashset.erase(s[left]);
                ++left;
            }
            hashset.insert(s[right]);
            res = max(right - left + 1, res);
        }

        return res;
    }
};

int main() {
    string S{"abcabcbb"};

    Solution solution;
    int result = solution.lengthOfLongestSubstring(S);
    cout << result << endl;

    return 0;
}
