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
    // // 暴力破解（优秀）
    // int findMagicIndex(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = -1;
    //     for (int i = 0; i < n; ++i) {
    //         if (nums[i] - i == 0) {
    //             return i;
    //         }
    //     }
    //     return ans;
    // }

    int getAnswer(vector<int>& nums, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        int leftAnswer = getAnswer(nums, left, mid - 1);
        if (leftAnswer != -1) {
             return leftAnswer;
        } else if (nums[mid] == mid) {
            return mid;
        }

        return getAnswer(nums, mid + 1, right);
    }

    // 二分剪枝
    int findMagicIndex(vector<int>& nums) {
        return getAnswer(nums, 0, static_cast<int>(nums.size() - 1));
    }
};

int main() {
    vector<int> dictionary{1, 1, 1};
    Solution solution;
    int result = solution.findMagicIndex(dictionary);
    cout << result << endl;

    return 0;
}
