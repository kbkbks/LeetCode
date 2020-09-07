/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

// Interview2
// 计算湖泊个数

/**
 * 常规dfs
 */
// vector<vector<bool> > visited;
// int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// bool inArea(int x, int y, int nr, int nc) {
//     return x >= 0 && x < nr && y >= 0 && y < nc;
// }

// void dfs(vector<vector<char> >& grid, int r, int c) {
//     int nr = grid.size();
//     int nc = grid[0].size();
//     visited[r][c] = true;
    
//     for (int i = 0; i < 4; ++i) {
//         int x = r + direction[i][0];
//         int y = c + direction[i][1];
//         if (inArea(x, y, nr, nc) && grid[x][y] == 'S' && !visited[x][y]) {
//             dfs(grid, x, y);
//         }
//     }
// }

// int main() {
//     // input
//     int M = 4, N = 5;
//     vector<vector<char> > grid = {
//         {'S', 'S', 'H', 'H', 'H'},
//         {'S', 'S', 'H', 'H', 'H'},
//         {'H', 'H', 'S', 'H', 'H'},
//         {'H', 'H', 'H', 'S', 'S'}
//     };

//     // global viriable
//     visited = vector<vector<bool> >(M, vector<bool>(N, false));

//     int num_islands = 0;
//     for (int r = 0; r < M; ++r) {
//         for (int c = 0; c < N; ++c) {
//             if (grid[r][c] == 'S' && !visited[r][c]) {
//                 ++num_islands;
//                 dfs(grid, r, c);
//             }
//         }
//     }

//     return 0;
// }


/**
 * 题解dfs
 */

void dfs(vector<vector<char> >& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();
    grid[r][c] = 'H';

    if (r - 1 >= 0 && grid[r - 1][c] == 'S') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == 'S') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == 'S') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == 'S') dfs(grid, r, c + 1);
}

int main() {
    // input
    int M = 4, N = 5;
    vector<vector<char> > grid = {
        {'S', 'S', 'H', 'H', 'H'},
        {'S', 'S', 'H', 'H', 'H'},
        {'H', 'H', 'S', 'H', 'H'},
        {'H', 'H', 'H', 'S', 'S'}
    };

    int num_islands = 0;
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (grid[r][c] == 'S') {
                ++num_islands;
                dfs(grid, r, c);
            }
        }
    }

    return 0;
}