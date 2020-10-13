/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * 小朋友拿糖果
 */

// struct People {
//     int candy;
//     int color;
//     People(int x, int y) : candy(x), color(y) {}
//     People() : candy(0), color(0) {}
// };

// int main() {
//     int num = 6;
//     vector<vector<int>> input = {
//         {2, 2},
//         {2, 1},
//         {3, 2},
//         {5, 2},
//         {3, 1},
//         {7, 2}
//     };

//     // Input
//     vector<People> array;
//     for (int i = 0; i < num; ++i) {
//         int a = input[i][0], b = input[i][1];
//         array.push_back(People(a, b));
//     }

//     // Index
//     unordered_map<int, int> idx1;
//     unordered_map<int, int> idx2;
//     for (int i = 0; i < array.size(); ++i) {
//         if (array[i].color == 1) idx1[array[i].candy] = i + 1;
//         else idx2[array[i].candy] = i + 1;
//     }

//     vector<int> arr1, arr2;
//     for (int i = 0; i < array.size(); ++i) {
//         if (array[i].color == 1) arr1.push_back(array[i].candy);
//         else arr2.push_back(array[i].candy);
//     }

//     sort(arr1.begin(), arr1.end());
//     sort(arr2.begin(), arr2.end());

//     vector<int> res1;
//     int sum1 = 0;
//     if (arr1.size() >= 3) {
//         for (int i = arr1.size() - 3; i < arr1.size(); ++i) {
//             sum1 += arr1[i];
//             res1.push_back(arr1[i]);
//         }
//     }

//     vector<int> res2;
//     int sum2 = 0;
//     if (arr2.size() >= 3) {
//         for (int i = arr2.size() - 3; i < arr2.size(); ++i) {
//             sum2 += arr2[i];
//             res2.push_back(arr2[i]);
//         }
//     }

//     if (sum1 == 0 && sum2 == 0) {
//         cout << "null" << endl;
//     } else {
//         if (sum1 > sum2) {
//             vector<int> ans{idx1[res1[0]], idx1[res1[1]], idx1[res1[2]]};
//             sort(ans.begin(), ans.end());
//             cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
//             cout << 1 << endl;
//             cout << sum1 << endl;
//         } else if (sum1 < sum2) {
//             vector<int> ans{idx2[res2[0]], idx2[res2[1]], idx2[res2[2]]};
//             sort(ans.begin(), ans.end());
//             cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
//             cout << 2 << endl;
//             cout << sum2 << endl;
//         } else if (sum1 == sum2) {
//             vector<int> ans1{idx1[res1[0]], idx1[res1[1]], idx1[res1[2]]};
//             vector<int> ans2{idx2[res2[0]], idx2[res2[1]], idx2[res2[2]]};
//             sort(ans1.begin(), ans1.end());
//             sort(ans2.begin(), ans2.end());
//             if (ans1[0] + ans1[1] + ans1[2] < ans2[0] + ans2[1] + ans2[2]) {
//                 cout << ans1[0] << " " << ans1[1] << " " << ans1[2] << endl;
//                 cout << 1 << endl;
//                 cout << sum1 << endl;            
//             } else {
//                 cout << ans2[0] << " " << ans2[1] << " " << ans2[2] << endl;
//                 cout << 2 << endl;
//                 cout << sum2 << endl;
//             }
//         }
//     }

//     return 0;
// }

/*
 * 岛屿数量(一般方法)
 */

// vector<vector<bool>> visited;
// int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// bool inArea(int x, int y, int nr, int nc) {
//     return x >= 0 && x < nr && y >= 0 && y < nc;
// }

// void dfs(vector<vector<char>> grid, int r, int c) {
//     int nr = grid.size(), nc = grid[0].size();
//     visited[r][c] = true;

//     for (int i = 0; i < 4; ++i) {
//         int x = r + direction[i][0];
//         int y = c + direction[i][1];
//         if (inArea(x, y, nr, nc) && grid[x][y] == 'S' && !visited[x][y]) {
//             dfs(grid, x, y);
//         }
//     }
// }

// int main() {
//     // input
//     int M = 4, N = 5;
//     vector<vector<char>> grid = {
//         {'S', 'S', 'H', 'H', 'H'},
//         {'S', 'S', 'H', 'H', 'H'},
//         {'H', 'H', 'S', 'H', 'H'},
//         {'H', 'H', 'H', 'S', 'S'}
//     };
    
//     // global viriable
//     visited = vector<vector<bool>>(M, vector<bool>(N, false));

//     int num_islands = 0;
//     for (int r = 0; r < M; ++r) {
//         for (int c = 0; c < N; ++c) {
//             if (grid[r][c] == 'S' && !visited[r][c]) {
//                 ++num_islands;
//                 dfs(grid, r, c);
//             }
//         }
//     }

//     return 0;
// }

/*
 * 岛屿数量(题解方法)
 */

// void dfs(vector<vector<char>> &grid, int r, int c) {
//     int nr = grid.size(), nc = grid[0].size();
//     grid[r][c] = 'H';
    
//     if (r - 1 >= 0 && grid[r - 1][c] == 'S') dfs(grid, r - 1, c);
//     if (r + 1 < nr && grid[r + 1][c] == 'S') dfs(grid, r + 1, c);
//     if (c - 1 >= 0 && grid[r][c - 1] == 'S') dfs(grid, r, c - 1);
//     if (c + 1 < nc && grid[r][c + 1] == 'S') dfs(grid, r, c + 1);
// }

// int main() {
//     // input
//     int M = 4, N = 5;
//     vector<vector<char>> grid = {
//         {'S', 'S', 'H', 'H', 'H'},
//         {'S', 'S', 'H', 'H', 'H'},
//         {'H', 'H', 'S', 'H', 'H'},
//         {'H', 'H', 'H', 'S', 'S'}
//     };

//     int num_islands = 0;
//     for (int r = 0; r < M; ++r) {
//         for (int c = 0; c < N; ++c) {
//             if (grid[r][c] == 'S') {
//                 ++num_islands;
//                 dfs(grid, r, c);
//             }
//         }
//     }

//     return 0;
// }

/*
 * 卡车运输
 */

// int knapsack(int K, int N, vector<int> w, vector<int> v, vector<vector<int>> f) {
//     for (int i = 1; i <= N; ++i) {
//         for (int j = 1; j <= K; ++j) {
//             if (w[i] > j) f[i][j] = f[i - 1][j];
//             else f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
//         }
//     }

//     return f[N][K];
// }

// int main() {
//     // input
//     int K = 9, N = 6;
//     vector<int> w = {0, 2, 2, 4, 6, 2, 8};
//     vector<int> v = {0, 3, 4, 8, 9, 6, 20};

//     vector<vector<int>> f(N + 1, vector<int>(K + 1, 0));
//     int result = knapsack(K, N, w, v, f);

//     return 0;
// }

/*
 * 卡车运输(降维)
 */

// int knapsack(int K, int N, vector<int> w, vector<int> v, vector<int> f) {
//     for (int i = 1; i <= N; ++i) {
//         for (int j = K; j >= 0; --j) {
//             if (w[j] <= j) f[j] = max(f[j], f[j - w[i]] + v[i]);
//         }
//     }
//     return f[K];
// }

// int main() {
//     // input
//     int K = 9, N = 6;
//     vector<int> w = {0, 2, 2, 4, 6, 2, 8};
//     vector<int> v = {0, 3, 4, 8, 9, 6, 20};

//     vector<int> f(K + 1, 0);
//     int result = knapsack(K, N, w, v, f);

//     return 0;
// }

/*
 * 卡车运输(满足卡车空间最大约束，实际上是满足恰好装满卡车约束)
 */

// int knapsack(int K, int N, vector<int> w, vector<int> v, vector<vector<int>> f) {
//     for (int i = 1; i <= N; ++i) {
//         for (int j = 0; j <= K; ++j) {
//             if (w[i] > j) f[i][j] = f[i - 1][j];
//             else f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
//         }
//     }

//     return *max_element(f[N].begin(), f[N].end());
// }

// int main() {
//     // input
//     int K = 9, N = 6;
//     vector<int> w = {0, 2, 2, 4, 6, 2, 8};
//     vector<int> v = {0, 3, 4, 8, 9, 6, 20};

//     vector<vector<int>> f(N + 1, vector<int>(K + 1, INT_MIN));
//     f[0][0] = 0;
    
//     int result = knapsack(K, N, w, v, f);

//     return 0;
// }

/*
 * 卡车运输(满足卡车空间最大约束)
 */

void capacity(int K, int N, vector<int> w, vector<int> v, vector<vector<bool>> &dp) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (w[j] > j) dp[i][j] = false;
            else dp[i][j] = true;
        }
    }
    return;
}

int knapsack(int K, int N, vector<int> w, vector<int> v, vector<vector<int>> f, vector<vector<bool>> dp) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (w[i] > j) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
        }
    }

    // 匹配dp载货量可达状态与f卡车价值状态
    int max_value = 0;
    for (int i = 0; i <= K; ++i) {
        if (dp[N][i] == true) max_value = max(max_value, f[N][i]);
    }
    return max_value;
}

int main() {
    // input
    int K = 9, N = 6;
    vector<int> w = {0, 2, 2, 4, 6, 2, 8};
    vector<int> v = {0, 3, 4, 8, 9, 6, 20};

    // 判断最大载货量，判断哪些载货量状态可达
    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));
    dp[0][0] = true;
    capacity(K, N, w, v, dp);

    // 确定实际可达的最大载货量
    vector<vector<int>> f(N + 1, vector<int>(K + 1, 0));
    int result = knapsack(K, N, w, v, f, dp);

    return 0;
}
