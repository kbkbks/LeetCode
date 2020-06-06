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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> ans(rows * columns);
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        int row = 0;
        int column = 0;
        int directionIndex = 0;
        for (int i = 0; i < rows * columns; ++i) {
            ans[i] = matrix[row][column];
            visited[row][column] = true;
            // cout << directions[0][0] << endl;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn] == true) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }

        return ans;
    }

 private:
    const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);

    return 0;
}
