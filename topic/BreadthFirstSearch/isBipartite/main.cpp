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
    // BFS
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans;
        queue<int> qu;
        if (graph.empty()) {
            return false;
        }
        unordered_set<int> set1, set2;

        vector<int> vertex;
        for (int i = 0; i < graph.size(); ++i) {
            vertex.push_back(i);
        }
        qu.push(vertex[0]);
        // 将0置入集合1
        set1.insert(vertex[0]);

        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            for (auto adj : graph[cur]) {
                
            }
        }
    }
};

int main() {
    vector<vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    Solution solution;
    bool result = solution.isBipartite(graph);
    cout << result << endl;

    return 0;
}
