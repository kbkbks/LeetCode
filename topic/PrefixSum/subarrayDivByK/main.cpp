/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    // // 暴力求解（超时）
    // int subarraysDivByK(vector<int>& A, int K) {
    //     int ans = 0;
    //     for (int i = 0; i < A.size(); ++i) {
    //         int sum = 0;
    //         for (int j = i; j < A.size(); ++j) {
    //             sum = A[j] + sum;
    //             if (sum % K == 0) ++ans;
    //         }
    //     }
    //     return ans;
    // }

    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int pre = 0;
        int ans = 0;
        mp[0] = 1;
        for (int i = 0; i < A.size(); ++i) {
            pre += A[i];
            int modulur = (pre % K + K) % K;
            if (mp.find(modulur) != mp.end()) ans += mp[modulur];
            ++mp[modulur];
        }

        return ans;
    }
};

int main() {
    vector<int> A{4, 5, 0, -2, -3, 1};
    int K = 5;

    Solution solution;
    int result = solution.subarraysDivByK(A, K);
    cout << result << endl;

    return 0;
}
