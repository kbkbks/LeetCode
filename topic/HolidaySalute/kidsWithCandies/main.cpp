/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
 public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int max = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); ++i) {
            vector<int> tmpcandies = candies;
            tmpcandies[i] = candies[i] + extraCandies;
            if (tmpcandies[i] >= max) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};

int main() {
    vector<int> candies{2, 3, 5, 1, 3};
    int extraCandies = 3;

    Solution solution;
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
    //cout << result << endl;

    return 0;
}
