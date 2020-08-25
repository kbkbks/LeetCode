/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
 public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;

        return helper(postorder, 0, postorder.size() - 1);
    }

    bool helper(vector<int> & postorder, int start, int end) {
        if (start >= end) return true;

        int p = start;
        while (postorder[p] < postorder[end]) p++;  // 左子树小于根节点
        int m = p;
        while (postorder[p] > postorder[end]) p++;  // 右子树大于根节点；

        return p == end && helper(postorder, start, m - 1) && helper(postorder, m, end - 1);
    }
};

int main() {
    vector<int> postorder{1, 3, 2, 6, 5};
    Solution solution;
    bool result = solution.verifyPostorder(postorder);

    return 0;
}
