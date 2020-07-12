/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
 public:
    Trie * next[26] = {nullptr};
    bool isEnd;

    Trie() {
        isEnd = false;
    }

    void insert(string s) {
        Trie * curPos = this;
        for (int i = s.size() - 1; i >= 0; --i) {
            int t = s[i] - 'a';
            if (curPos->next[t] == nullptr) {
                curPos->next[t] = new Trie();
            }
            curPos = curPos->next[t];
        }
        curPos->isEnd = true;
    }
};

class Solution {
 public:
    // 字典树
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        int inf = 0x3f3f3f3f;
        Trie * root = new Trie();
        for (auto &word : dictionary) {
            root->insert(word);
        }

        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            Trie * curPos = root;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a';
                if (curPos->next[t] == nullptr) {
                    break;
                } else if (curPos->next[t]->isEnd) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};

int main() {
    vector<string> dictionary{"looked", "just", "like", "her", "brother"};
    string sentence{"jesslookedjustliketimherbrother"};
    Solution solution;
    int result = solution.respace(dictionary, sentence);
    cout << result << endl;

    return 0;
}
