/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

int nr, nc;
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> grid;

bool inArea(int x, int y) {
    return x >= 0 && x < nr && y >= 0 && y < nc;
}

int dfs(int r, int c, int length, vector<vector<bool>>& visited) {
    visited[r][c] = true;
    int maxVal = length;
    for (int i = 0; i < 4; ++i) {
        int x = r + direction[i][0];
        int y = c + direction[i][1];
        if (inArea(x, y) && grid[x][y] < grid[r][c] && !visited[x][y]) {
            int ans = dfs(x, y, length + 1,visited);
            maxVal = max(ans, maxVal);
        }
    }
    visited[r][c] = false;
    return maxVal;
}

int main() {
    nr = 2, nc = 3;
    grid = {{8, 4, 1}, {6, 5, 2}};
    int res = 0;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            vector<vector<bool>> visited(2, vector<bool>(3, false));
            int ans = dfs(r, c, 1, visited);
            res = max(ans, res);
        }
    }
    return 0;
}
