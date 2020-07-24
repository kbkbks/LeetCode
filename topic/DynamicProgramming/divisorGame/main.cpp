/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
 public:
    // // 找规律法(数字归纳证明)
    // bool divisorGame(int N) {
    //     return N % 2 == 0;
    // }

    // 递推
    bool divisorGame(int N) {
        vector<int> f(N + 2, false);
        f[1] = false;
        f[2] = true;
        for (int i = 3; i <= N; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0 && !f[i - j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[N];
    }
};

int main() {
    int N = 4;
    Solution solution;
    int result = solution.divisorGame(N);
    cout << result << endl;

    return 0;
}
