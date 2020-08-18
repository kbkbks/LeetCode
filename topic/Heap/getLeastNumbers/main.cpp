/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class Solution {
 public:
    /**
     * STL函数
     */
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        arr.erase(arr.begin() + k, arr.end());
        return arr;
    }

    // /**
    //  * 堆排序（优先队列）
    //  */
    // vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //     vector<int> res(k, 0);
    //     if (k == 0) return {};
    //     priority_queue<int> Q;
    //     for (int i = 0; i < k; ++i) {
    //         Q.push(arr[i]);
    //     }
    //     for (int i = k; i < arr.size(); ++i) {
    //         if (Q.top() > arr[i]) {
    //             Q.pop();
    //             Q.push(arr[i]);
    //         }
    //     }
    //     for (int i = 0; i < res.size(); ++i) {
    //         res[i] = Q.top();
    //         Q.pop();
    //     }
    //     return res;
    // }
};

int main() {
    vector<int> arr{3, 2, 1};
    int k = 2;
    Solution solution;
    vector<int> result = solution.getLeastNumbers(arr, k);

    return 0;
}
