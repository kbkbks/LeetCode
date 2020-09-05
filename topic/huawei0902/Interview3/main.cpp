/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

// Interview2
// 卡车运输

/**
 * 01背包问题
 */
int knapsack(int K, int N, vector<int> w, vector<int> v, vector<vector<int> > f) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (w[i] > j) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
        }
    }

    return f[N][K];
}

int main() {
    int K = 9, N = 6;
    vector<int> w = {0, 2, 2, 4, 6, 2, 8};
    vector<int> v = {0, 3, 4, 8, 9, 6, 20};

    vector<vector<int> > f(N + 1, vector<int>(K + 1, 0));
    // f[0][0] = 0;
    int result = knapsack(K, N, w, v, f);
    
    return 0;
}


/**
 * 降维
 */
// int knapsack(int K, int N, vector<int> w, vector<int> v, vector<int> f) {
//     for (int i = 1; i <= N; ++i) {
//         for (int j = K; j >=0; --j) {
//             if (w[i] <= j) f[j] = max(f[j], f[j - w[i]] + v[i]);
//         }
//     }
//     return f[K];
// }

// int main() {
//     int K = 9, N = 5;
//     vector<int> w = {0, 2, 2, 4, 6, 3};
//     vector<int> v = {0, 3, 4, 8, 9, 6};

//     vector<int> f(K + 1, 0);
//     int result = knapsack(K, N, w, v, f);

//     return 0;
// }