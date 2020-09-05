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
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0|| matrix[0].size() == 0) return {};

        int nr = matrix.size(), nc = matrix[0].size();
        int total = nr * nc;
        vector<vector<bool> > visited(nr, vector<bool>(nc, false));
        vector<int> res(total);

        int r = 0, c = 0;
        int directionIdx = 0;
        for (int i = 0; i < total; ++i) {
            res[i] = matrix[r][c];
            visited[r][c] = true;
            int x = r + direction[directionIdx][0];
            int y = c + direction[directionIdx][1];
            if (x < 0 || x >= nr || y < 0 || y >= nc || visited[x][y]) {
                directionIdx = (directionIdx + 1) % 4;
            }
            r += direction[directionIdx][0];
            c += direction[directionIdx][1];
        }
        return res;
    }
};

int main() {
    vector<vector<int> > matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);

    return 0;
}
