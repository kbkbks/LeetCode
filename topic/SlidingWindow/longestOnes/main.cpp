/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, cnt = 0, res = 0;
        while (right < A.size()) {
            if (A[right] == 0) cnt++;
            while (cnt > K) {
                if (A[left] == 0) cnt--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};

int main() {
    vector<int> A = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    Solution solution;
    int result = solution.longestOnes(A, k);

    return 0;
}
