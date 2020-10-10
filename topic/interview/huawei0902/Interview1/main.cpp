/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

// bool cmp(const People * A, const People * B) {
//     return A->candy < B->candy;
// }

struct People {
    int candy;
    int color;
    People(int x, int y) : candy(x), color(y) {}
    People() : candy(0), color(0) {}
};

int main() {
    int num = 6;
    vector<vector<int>> input = {
        {2, 2},
        {2, 1},
        {3, 2},
        {5, 2},
        {3, 1},
        {7, 2}
    };

    // Input
    vector<People> array;
    for (int i = 0; i < num; ++i) {
        int a = input[i][0], b = input[i][1];
        array.push_back(People(a, b));
    }

    // Index
    unordered_map<int, int> idx1;
    unordered_map<int, int> idx2;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i].color == 1) idx1[array[i].candy] = i + 1;
        else idx2[array[i].candy] = i + 1;
    }

    vector<int> arr1, arr2;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i].color == 1) arr1.push_back(array[i].candy);
        else arr2.push_back(array[i].candy);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> res1;
    int sum1 = 0;
    if (arr1.size() >= 3) {
        for (int i = arr1.size() - 3; i < arr1.size(); ++i) {
            sum1 += arr1[i];
            res1.push_back(arr1[i]);
        }
    }

    vector<int> res2;
    int sum2 = 0;
    if (arr2.size() >= 3) {
        for (int i = arr2.size() - 3; i < arr2.size(); ++i) {
            sum2 += arr2[i];
            res2.push_back(arr2[i]);
        }
    }

    if (sum1 == 0 && sum2 == 0) {
        cout << "null" << endl;
    } else {
        if (sum1 > sum2) {
            vector<int> ans{idx1[res1[0]], idx1[res1[1]], idx1[res1[2]]};
            sort(ans.begin(), ans.end());
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
            cout << 1 << endl;
            cout << sum1 << endl;
        } else if (sum1 < sum2) {
            vector<int> ans{idx2[res2[0]], idx2[res2[1]], idx2[res2[2]]};
            sort(ans.begin(), ans.end());
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
            cout << 2 << endl;
            cout << sum2 << endl;
        } else if (sum1 == sum2) {
            vector<int> ans1{idx1[res1[0]], idx1[res1[1]], idx1[res1[2]]};
            vector<int> ans2{idx2[res2[0]], idx2[res2[1]], idx2[res2[2]]};
            sort(ans1.begin(), ans1.end());
            sort(ans2.begin(), ans2.end());
            if (ans1[0] + ans1[1] + ans1[2] < ans2[0] + ans2[1] + ans2[2]) {
                cout << ans1[0] << " " << ans1[1] << " " << ans1[2] << endl;
                cout << 1 << endl;
                cout << sum1 << endl;
            } else {
                cout << ans2[0] << " " << ans2[1] << " " << ans2[2] << endl;
                cout << 2 << endl;
                cout << sum2 << endl;
            }
        }
    }

    return 0;
}
