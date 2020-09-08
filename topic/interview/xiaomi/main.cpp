/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<bool>> visited;
int nr, nc;

bool inArea(int x, int y) {
    return x >= 0 && x < nc && y >= 0 && y < nr;
}

bool dfs(int r, int c, int ch, string word, vector<vector<char>> array) {
    visited[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int x = r + direction[i][0];
        int y = c + direction[i][1];
        if (array[x][y] == word[word.size() - 1]) return true;
        if (inArea(x, y) && array[x][y] == word[ch + 1] && !visited[x][y]) {
            dfs(x, y, ch + 1, word, array);
        }
    }
    visited[r][c] = false; 
    return false;
}

int main() {
    vector<vector<char>> array = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "SEW";
    visited = vector<vector<bool>>(4, vector<bool>(3));
    nr = array.size(), nc = array[0].size();
    bool res;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (array[r][c] == word[0] && !visited[r][c]) {
                res = dfs(r, c, 0, word, array);
                if (res) break;
            }
        }
    }
    return 0;
}
