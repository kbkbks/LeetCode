/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    bool check() {
        for (const auto& p : indexT) {
            if (indexS[p.first] < p.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        string ans;
        int l = 0, r = 0;
        int len = INT32_MAX;

        for (int i = 0; i < t.size(); ++i) {
            if (indexT.find(t[i]) == indexT.end()) {
                indexT.insert(pair<char, int>(t[i], 1));
            } else {
                indexT[t[i]] = indexT[t[i]] + 1;
            }
        }

        while (r < s.size()) {
            if (indexT.find(s[r]) != indexT.end()) {
                ++indexS[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    ans = s.substr(l, r - l + 1);
                    len = r - l + 1;
                }
                if (indexT.find(s[l]) != indexT.end()) {
                    --indexS[s[l]];
                }
                ++l;
            }
            ++r;
        }

        return ans;
    }

 private:
    unordered_map<char, int> indexT, indexS;
};

int main() {
    string S{"ADOBECODEBANC"};
    string T{"ABC"};

    Solution solution;
    string result = solution.minWindow(S, T);
    cout << result << endl;

    return 0;
}
