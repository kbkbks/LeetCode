/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[cnt]) {
                stk.pop();
                ++cnt;
            }
            // if (i == n - 1 && !stk.empty() && stk.top() != popped[cnt]) return false;    // 也可以
        }
        return cnt == n;    //  更简洁
    }
};

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    Solution solution;
    bool result = solution.validateStackSequences(pushed, popped);
    cout << result << endl;

    return 0;
}
