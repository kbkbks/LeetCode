/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution{
 public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        for (auto word : wordDict) {
            wordDictSet.insert(word);
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    string s{"leetcode"};
    vector<string> wordDict{"leet", "code"};
    Solution solution;
    bool result = solution.wordBreak(s, wordDict);
    cout << result << endl;

    return 0;
}
