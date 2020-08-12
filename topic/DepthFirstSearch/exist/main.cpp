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
    int m;  // 行数
    int n;  // 列数
    vector<vector<bool>> visited;
    vector<vector<char>> board;
    string word;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y>= 0 && y < n;
    }

    bool dfs(int i, int j, int start) {
        if (start == word.size() - 1) {
            return board[i][j] == word[start];
        }
        if (board[i][j] == word[start]) {
            visited[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                int x = i + directions[k][0];
                int y = j + directions[k][1];
                if (inArea(x, y) && !visited[x][y]) {
                    if (dfs(x, y, start + 1)) return true;
                }
            }
            visited[i][j] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        this->board = board;
        this->word = word;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                 if (dfs(i, j, 0)) return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board ={
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = {"ABCCED"};
    Solution solution;
    bool result = solution.exist(board, word);
    cout << result << endl;

    return 0;
}
