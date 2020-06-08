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

/*
 * 程序未完成，对于同一层上的单词，无法重复读取同一个邻接单词
 * （事实要求需要重复读取，并保留多个prev）
 * 
 */

class Solution {
 public:
    // 最短路径（广度优先搜索）
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> startWordSet;   // 字典中的转换起点
        vector<vector<string>> ans;
        // 校验endWord是否在字典wordList中
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                break;
            } else if (i == wordList.size() -1 && wordList[i] != endWord) {
                return {};
            }
        }

        // 判断beginWord是否可以转换，并保存转换起始点
        for (int i = 0; i < wordList.size(); ++i) {
            if (beginWord.size() != wordList[i].size()) {
                return {};
            } else {
                // 计算字典中单词与beginWord的差异度
                int diff = 0;
                for (int j = 0; j < wordList[i].size(); ++j) {
                    if (beginWord[j] != wordList[i][j]) {
                        ++diff;
                    }
                }
                // 保存转换起始点
                if (diff == 1) {
                    startWordSet.push_back(wordList[i]);
                }
            }
        }

        if (startWordSet.size() == 0) return {};
        // 建立邻接表
        buildAjacencyList(wordList);
        // 对起始点集合所有起始点进行bfs
        for (int i = 0; i < startWordSet.size(); ++i) {
            bfs(startWordSet[i], endWord);
            // 重置已访问节点
            for (auto iter = visited.begin(); iter != visited.end(); ++iter) {
                iter->second = false;
            }
        }
        int minsize = INT64_MAX;
        for (auto iter = allSequence.begin(); iter != allSequence.end(); ++iter) {
            if (iter->second[0].size() < minsize) {
                minsize = iter->second[0].size();
                ans.clear();
                ans = iter->second;
            } else if (iter->second[0].size() == minsize) {
                ans.insert(ans.end(), iter->second.begin(), iter->second.end());
            }
        }

        for (int i = 0; i < ans.size(); ++i) {
            ans[i].insert(ans[i].begin(), beginWord);
        }

        return ans;
    }

    string checkStringDiff(string first, string second) {
        int diff = 0;
        for (int i = 0; i < second.size(); ++i) {
            if (first[i] != second[i]) {
                ++diff;
            }
        }
        if (diff == 1) {
            return second;
        } else {
            return {};
        }
    }

    void buildAjacencyList(const vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < wordList.size(); ++j) {
                if (j == i) continue;
                string adjWord = checkStringDiff(wordList[i], wordList[j]);
                if (adjWord.size() != 0 && AdjacencyList.find(wordList[i]) == AdjacencyList.end()) {
                    AdjacencyList[wordList[i]] = vector<string>{wordList[j]};
                    visited[wordList[i]] = false;
                } else if (adjWord.size() != 0) {
                    AdjacencyList[wordList[i]].push_back(wordList[j]);
                }
            }
        }
    }

    void bfs(string startWord, string endWord) {
        queue<string> wordQu;   // 单词队列
        vector<string> wordSequence;    // 转换序列
        unordered_map<string, string> prev;     // 搜索路径
        // unordered_map<string, vector<string>> prev;     // 搜索路径
        bool flag = false;  // 搜索标志位
        wordQu.push(startWord);
        visited[startWord] = true;  // 首节点已访问
        if (startWord == endWord) {
            wordSequence = vector<string>{endWord};
            allSequence[startWord] = vector<vector<string>>{{endWord}};
        } else {
            while (!wordQu.empty()) {
                // vector<string> tmp;     // 层序单词
                int len = wordQu.size();
                for (int i = 0; i < len; ++i) {
                    // 取出当前队列的头节点
                    string currentWord = wordQu.front();
                    wordQu.pop();
                    // visited[currentWord] = true;
                    // tmp.push_back(currentWord);     // 记录层序单词
                    for (auto adj : AdjacencyList[currentWord]) {
                        if (!visited[adj]) {
                            prev[adj] = currentWord;
                            if (adj == endWord) {
                                // 转换到目标单词
                                flag = true;
                                wordSequence = getSequence(prev, startWord, endWord, wordSequence);  // 找到一条转换序列
                                if (allSequence.find(startWord) == allSequence.end()) {
                                    allSequence[startWord] = vector<vector<string>>{wordSequence};
                                } else {
                                    allSequence[startWord].push_back(wordSequence);
                                }
                                wordSequence.clear();
                            }
                            wordQu.push(adj);
                            if (adj != endWord) {
                                visited[adj] = true;
                            }
                        }
                    }
                }
                if (flag) break;
            }
        }
    }

    vector<string> getSequence(unordered_map<string, string> prev, string startWord, string endWord, vector<string> wordSequence) {
        if (prev.find(endWord) != prev.end() && startWord != endWord) {
            wordSequence = getSequence(prev, startWord, prev[endWord], wordSequence);
        }
        wordSequence.push_back(endWord);
        return wordSequence;
    }

 private:
    unordered_map<string, vector<string>> AdjacencyList;    // 邻接表
    unordered_map<string, bool> visited;    // 已访问的单词，设为true
    unordered_map<string, vector<vector<string>>> allSequence;  // 所有起始点转换序列
};

int main() {
    string beginWord = {"hit"};
    string endWord = {"cog"};
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    // vector<string> wordList = {"hot", "dog", "dot"};
    // vector<string> wordList = {"flail","halon","lexus","joint","pears","slabs","lorie","lapse","wroth","yalow","swear","cavil","piety","yogis","dhaka","laxer","tatum","provo","truss","tends","deana","dried","hutch","basho","flyby","miler","fries","floes","lingo","wider","scary","marks","perry","igloo","melts","lanny","satan","foamy","perks","denim","plugs","cloak","cyril","women","issue","rocky","marry","trash","merry","topic","hicks","dicky","prado","casio","lapel","diane","serer","paige","parry","elope","balds","dated","copra","earth","marty","slake","balms","daryl","loves","civet","sweat","daley","touch","maria","dacca","muggy","chore","felix","ogled","acids","terse","cults","darla","snubs","boats","recta","cohan","purse","joist","grosz","sheri","steam","manic","luisa","gluts","spits","boxer","abner","cooke","scowl","kenya","hasps","roger","edwin","black","terns","folks","demur","dingo","party","brian","numbs","forgo","gunny","waled","bucks","titan","ruffs","pizza","ravel","poole","suits","stoic","segre","white","lemur","belts","scums","parks","gusts","ozark","umped","heard","lorna","emile","orbit","onset","cruet","amiss","fumed","gelds","italy","rakes","loxed","kilts","mania","tombs","gaped","merge","molar","smith","tangs","misty","wefts","yawns","smile","scuff","width","paris","coded","sodom","shits","benny","pudgy","mayer","peary","curve","tulsa","ramos","thick","dogie","gourd","strop","ahmad","clove","tract","calyx","maris","wants","lipid","pearl","maybe","banjo","south","blend","diana","lanai","waged","shari","magic","duchy","decca","wried","maine","nutty","turns","satyr","holds","finks","twits","peaks","teems","peace","melon","czars","robby","tabby","shove","minty","marta","dregs","lacks","casts","aruba","stall","nurse","jewry","knuth"};
    Solution solution;
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);

    return 0;
}
