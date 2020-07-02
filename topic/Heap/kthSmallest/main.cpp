/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
 public:
    // 直接排序
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans;
        vector<int> arr;
        for (auto row : matrix) {
            arr.insert(arr.end(), row.begin(), row.end());
            // for (int it : row) {
            //     arr.push_back(it);
            // }
        }
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }

    // 归并排序（详见23题 合并K个排序链表）
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    }
};

int main() {
    vector<vector<int>> matrix{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    Solution solution;
    int result = solution.kthSmallest(matrix, k);
    cout << result << endl;

    return 0;
}
