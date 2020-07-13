/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    vector<int> divingBoard(int shorter, int longer, size_t k) {
        if (k == 0) {
            return vector<int>();
        }

        if (shorter == longer) {
            return vector<int>(1, shorter * k);
        }

        vector<int> lengths(k + 1);
        for (int i = 0; i < lengths.size(); ++i) {
            lengths[i] = shorter * (k - i) + longer * i;
        }

        return lengths;
    }
};

int main() {
    int shorter = 1;
    int longer = 2;
    size_t k = 3;
    Solution solution;
    vector<int> result = solution.divingBoard(shorter, longer, k);

    return 0;
}
