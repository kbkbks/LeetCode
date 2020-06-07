/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
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
    // 最短路径（广度优先搜索）
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        // 校验endWord是否在字典worsList中
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                continue;
            } else if (i == wordList.size() -1 && wordList[i] != endWord) {
                return {};
            }
        }


        return {{"ok"}};
    }
};

int main() {
    string beginWord = {"hit"};
    string endWord = {"cog"};
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    Solution solution;
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);

    return 0;
}
