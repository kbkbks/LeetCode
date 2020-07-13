/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            map1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            map2[nums2[i]]++;
        }

        for (auto iter = map1.begin(); iter != map1.end(); ++iter) {
            if (map2[iter->first]) {
                int n = min(map1[iter->first], map2[iter->first]);
                for (int i = 0; i < n; ++i) {
                    ans.push_back(iter->first);
                }
            }
        }

        return ans;
    }
};

int main() {
    // vector<int> nums1{1, 2, 2, 1};
    // vector<int> nums2{2, 2};
    vector<int> nums1{4, 9, 5};
    vector<int> nums2{9, 4, 9, 8, 4};
    Solution solution;
    vector<int> result = solution.intersect(nums1, nums2);

    return 0;
}
