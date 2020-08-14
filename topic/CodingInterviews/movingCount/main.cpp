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
    int directions[2][2] = {{1, 0}, {0, 1}};

    int get(int x) {
        int res = 0;
        for (; x ; x /= 10) {
            res += x % 10;
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int, int>> qu;   // 坐标
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        qu.push(make_pair(0, 0));
        visited[0][0] = true;
        ans = 1;
        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();
            for (int i = 0; i < 2; ++i) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] || get(newX) + get(newY) > k) continue;
                qu.push(make_pair(newX,  newY));
                visited[newX][newY] = true;
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    int m = 2, n = 3, k = 1;
    Solution solution;
    int result = solution.movingCount(m, n, k);

    return 0;
}
