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
#include <sstream>
#include <stack>

using namespace std;

class Solution {
 public:
    /**
     * DFS常规方法
     */
    // int nr;
    // int nc;
    // vector<vector<bool> > visited;
    // int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // bool inArea(int x, int y) {
    //     return x >= 0 && x < nr && y >= 0 && y < nc;
    // }

    // void dfs(vector<vector<char> >& grid, int r, int c) {
    //     visited[r][c] = true;
    //     for (int i = 0; i < 4; ++i) {
    //         int x = r + directions[i][0];
    //         int y = c + directions[i][1];
    //         if (inArea(x, y) && grid[x][y] == '1' && !visited[x][y]) {
    //             dfs(grid, x, y);
    //         }
    //     }
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     nr = grid.size();
    //     if (nr == 0) return 0;
    //     nc = grid[0].size();
    //     visited = vector<vector<bool> >(nr, vector<bool>(nc, false));

    //     int num_islands = 0;
    //     for (int r = 0; r < nr; ++r) {
    //         for (int c = 0; c < nc; ++c) {
    //             if (grid[r][c] == '1' && !visited[r][c]) {
    //                 ++num_islands;
    //                 dfs(grid, r, c);
    //             }
    //         }
    //     }
    //     return num_islands;
    // }

    /**
     * DFS题解方法
     */
    void dfs(vector<vector<char> >& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (nr == 0) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }
        return num_islands;
    }

    /**
     * BFS题解方法
     */
    // int numIslands(vector<vector<char>>& grid) {
    //     int nr = grid.size();
    //     if (nr == 0) return 0;
    //     int nc = grid[0].size();

    //     int num_islands = 0;
    //     for (int r = 0; r < nr; ++r) {
    //         for (int c = 0; c < nc; ++c) {
    //             if (grid[r][c] == '1') {
    //                 ++num_islands;
    //                 grid[r][c] = '0';
    //                 queue<pair<int, int> > qu;
    //                 qu.push({r, c});
    //                 while (!qu.empty()) {
    //                     auto neighbor = qu.front();
    //                     qu.pop();
    //                     int row = neighbor.first, col = neighbor.second;
    //                     if (row - 1 >= 0 && grid[row - 1][col] == '1') {
    //                         grid[row - 1][col] = '0';
    //                         qu.push({row - 1, col});
    //                     }
    //                     if (row + 1 < nr && grid[row + 1][col] == '1') {
    //                         grid[row + 1][col] = '0';
    //                         qu.push({row + 1, col});
    //                     }
    //                     if (col - 1 >= 0 && grid[row][col - 1] == '1') {
    //                         grid[row][col - 1] = '0';
    //                         qu.push({row, col - 1});
    //                     }
    //                     if (col + 1 < nc && grid[row][col + 1] == '1') {
    //                         grid[row][col + 1] = '0';
    //                         qu.push({row, col + 1});
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return num_islands;
    // }

    /**
     * BFS题解方法(常规解法)
     */
    // int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // int nr;
    // int nc;
    // vector<vector<bool> > visited;

    // bool inArea(int x, int y) {
    //     return x >= 0 && x < nr && y >= 0 && y < nc;
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     nr = grid.size();
    //     if (nr == 0) return 0;
    //     nc = grid[0].size();
    //     visited = vector<vector<bool> >(nr, vector<bool>(nc, false));

    //     int num_islands = 0;
    //     for (int r = 0; r < nr; ++r) {
    //         for (int c = 0; c < nc; ++c) {
    //             if (grid[r][c] == '1' && !visited[r][c]) {
    //                 ++num_islands;
    //                 visited[r][c] = true;
    //                 queue<pair<int, int> > qu;
    //                 qu.push({r, c});
    //                 while (!qu.empty()) {
    //                     auto neighbor = qu.front();
    //                     qu.pop();
    //                     int row = neighbor.first, col = neighbor.second;
    //                     for (int i = 0; i < 4; ++i) {
    //                         int x = row + direction[i][0];
    //                         int y = col + direction[i][1];
    //                         if (inArea(x, y) && grid[x][y] == '1' && !visited[x][y]) {
    //                             visited[x][y] = true;
    //                             qu.push({x, y});
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return num_islands;
    // }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    Solution solution;
    int result = solution.numIslands(grid);
    cout << result << endl;

    return 0;
}
