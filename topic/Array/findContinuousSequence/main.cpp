/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
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
    /**
     * 自己写的快慢双指针
     */
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int low = 1, fast = 2;
        int sum = low + fast;
        tmp.push_back(low);
        tmp.push_back(fast);
        while (low < fast) {
            if (sum == target) {
                res.push_back(tmp);
                fast++;
                sum += fast;
                tmp.push_back(fast);
            } else if (sum < target) {
                fast++;
                sum += fast;
                tmp.push_back(fast);
            } else if (sum > target) {
                low++;
                int sub = tmp.front();
                tmp.erase(tmp.begin());
                sum -= sub;
            }
        }

        return res;
    }
};

int main() {
    int target = 9;
    Solution solution;
    vector<vector<int>> result = solution.findContinuousSequence(target);

    return 0;
}
