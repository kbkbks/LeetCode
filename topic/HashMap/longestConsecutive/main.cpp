/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    // // 并查集
    // int find(int x) {
    //     return a.count(x) ? a[x] = find(a[x]) : x;
    // }
    // int longestConsecutive(vector<int>& nums) {
    //     for (auto i : nums) {
    //         a[i] = i + 1;
    //     }
    //     int ans = 0;
    //     for (auto i : nums) {
    //         int y = find(i + 1);
    //         ans = max(ans, y - i);
    //     }
    //     return ans;
    // }

    // 并查集二
    // cnt用于记录当前集合的元素个数
    unordered_map<int, int> uf, cnt;

    int find(int i) {
        return i == uf[i] ? i: uf[i] = find(uf[i]);
    }

    int merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return cnt[x];
        uf[y] = x;
        // 更新合并之后的连通分量的元素个数
        cnt[x] += cnt[y];
        return cnt[x];
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        for (int i : nums) uf[i] = i, cnt[i] = 1;
        int ans = 1;
        for (int i : nums) {
            if (i != INT64_MAX && uf.count(i+1)) {
                ans = max(ans, merge(i, i+1));
            }
        }
        return ans;
    }

 private:
    // unordered_map<int, int> a;
};

int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution solution;
    int result = solution.longestConsecutive(nums);
    cout << result << endl;

    return 0;
}
