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
        unordered_map<int, int> visited;
        if (graph.empty()) {
            return false;
        }

        vector<int> vertex;
        for (int i = 0; i < graph.size(); ++i) {
            vertex.push_back(i);
        }

        qu.push(vertex[0]);
        // 将0置入集合1
        set1.insert(vertex[0]);
        // visited[vertex[0]] = true;

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
                if (!visited.count(cur) || visited[cur] != adj) {
                    if (curSet.count(adj)) {
                        return false;
                    } else if (!adjSet.count(adj)) {
                        adjSet.insert(adj);
                    }
                    qu.push(adj);
                    // visited[adj] = true;
                    visited[cur] = adj;
                    visited[adj] = cur;
                }
            }
        }
        return true;
    }

 private:
    unordered_set<int> set1, set2;
    unordered_set<int> &curSet;
    unordered_set<int> &adjSet;
};

int main() {
    vector<vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    // vector<vector<int>> graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    Solution solution;
    bool result = solution.isBipartite(graph);
    cout << result << endl;

    return 0;
}
