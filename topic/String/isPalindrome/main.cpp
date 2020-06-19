/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string str;
        for (char ch : s) {
            if (isalnum(ch)) {
                str += ch;
            }
        }

        for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};

int main() {
    string s{"A man, a plan, a canal: Panama"};
    Solution solution;
    bool result = solution.isPalindrome(s);
    cout << result << endl;

    return 0;
}
