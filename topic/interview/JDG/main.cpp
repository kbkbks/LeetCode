/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

// Interview1

// class Solution{
//  public:

// };

/**
 * 逆序五进制
 */
// int main() {
//     // int num = 1000;
//     int num = 77267;
//     string str = to_string(num);
//     reverse(str.begin(), str.end());
//     int renum = stoi(str);
//     int mod;
//     vector<int> res;
//     while (renum) {
//         mod = renum % 5;
//         res.push_back(mod);
//         renum /= 5;
//     }
//     reverse(res.begin(), res.end());
//     for (int i = 0; i < res.size(); ++i) {
//         cout << res[i];
//     }

//     return 0;
// }


int main() {
    int total = 3, num = 3;
    // cin >> total >> num;
    vector<int> damage{1, 2, 2};
    // for (int i = 0; i < num; ++i) {
    //     int tmp;
    //     cin >> tmp;
    //     damage[i] = tmp;
    // }
    int mod = 1e9 + 7;
    // vector<int> dp(total);
    // dp[0] = 0;
    sort(damage.begin(), damage.end());
    int cnt = 0;
    for (int i = 0; i < damage.size(); ++i) {
        int sum = 0;
        while (sum + damage[i] < total) {
            sum += damage[i];
            if (sum == total) {
                cnt++;
                sum -= damage[i];
                break;
            }
        }
        if (sum + damage[i] > total) {
            
        }

    }


    return 0;
}
