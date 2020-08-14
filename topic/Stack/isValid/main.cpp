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
    bool isValid(string s) {
        if (s == "") return true;
        if (s.size() % 2 == 1) return false;

        unordered_map<char, char> hashmap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;

        for (auto ch : s) {
            if (hashmap.count(ch)) {
                if (stk.size() == 0 || stk.top() !=  hashmap[ch]) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

int main() {
    string s{"()[]{}"};
    Solution solution;
    bool result = solution.isValid(s);
    cout << result << endl;

    return 0;
}
