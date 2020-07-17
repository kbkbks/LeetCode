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
#include <unordered_set>

using namespace std;

class Solution {
 public:
    Solution() : curSet(set1), adjSet(set2) {

    }

    // BFS
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans;
        queue<int> qu;
        // vector<bool> visited;
        if (graph.empty()) {
            return false;
        }

        vector<int> vertex;
        for (int i = 0; i < graph.size(); ++i) {
            vertex.push_back(i);
        }

        for (int i = 0; i < graph.size(); ++i) {
            if (!set1.count(vertex[i]) && !set2.count(vertex[i])) {
                qu.push(vertex[i]);
                // 将0置入集合1
                set1.insert(vertex[i]);

                while (!qu.empty()) {
                    int cur = qu.front();
                    qu.pop();
                    if (set1.count(cur)) {
                        unordered_set<int> tmp = set2;
                        curSet = set1;
                        adjSet = tmp;
                    } else {
                        unordered_set<int> tmp = set1;
                        curSet = set2;
                        adjSet = tmp;
                    }
                    for (auto adj : graph[cur]) {
                        if (curSet.count(adj)) {
                            return false;
                        } else if (!adjSet.count(adj)) {
                            adjSet.insert(adj);
                            qu.push(adj);
                        }
                    }
                }
            }
        }

        return true;
    }

 private:
    unordered_set<int> set1, set2;
    unordered_set<int> &curSet;
    unordered_set<int> &adjSet;

//     // BFS + 染色法
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> color(n, 0);
//         for (int i = 0; i < n; ++i) {
//             if (color[i] == UNCOLORED) {
//                 queue<int> qu;
//                 qu.push(i);
//                 color[i] = RED;
//                 while (!qu.empty()) {
//                     int node = qu.front();
//                     int cNei = (color[node] == RED ? GREEN : RED);
//                     qu.pop();
//                     for (int adj : graph[node]) {
//                         if (color[adj] == UNCOLORED) {
//                             color[adj] = cNei;
//                             qu.push(adj);
//                         } else if (color[adj] != cNei) {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         }
//         return true;
//     }

//  private:
//     static constexpr int UNCOLORED = 0;
//     static constexpr int RED = 1;
//     static constexpr int GREEN = 2;
//     vector<int> color;
};

int main() {
    // vector<vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    vector<vector<int>> graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    Solution solution;
    bool result = solution.isBipartite(graph);
    cout << result << endl;

    return 0;
}
