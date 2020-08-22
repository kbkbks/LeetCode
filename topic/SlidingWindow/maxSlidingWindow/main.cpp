/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class MonotonicQueue {
 private:
    deque<int> dq;

 public:
    void push(int n) {
        while (!dq.empty() && dq.back() < n) {
            dq.pop_back();
        }
        dq.push_back(n);
    }

    int max() {
        return dq.front();
    }

    void pop(int n) {
        if (!dq.empty() && dq.front() == n) {
            dq.pop_front();
        }
    }
};

class Solution {
 public:
    // /**
    //  * 暴力破解
    //  */
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     if (nums.empty()) return {};
    //     vector<int> res;
    //     for (int i = 0; i < nums.size() - k + 1; ++i) {
    //         int maxValue = INT_MIN;
    //         for (int j = i; j < i + k; ++j) {
    //             maxValue = max(maxValue, nums[j]);
    //         }
    //         res.push_back(maxValue);
    //     }
    //     return res;
    // }

    /**
     * 单调队列（MonotonicQueue）
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonicQueue mq;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                mq.push(nums[i]);
            } else {
                mq.push(nums[i]);
                res.push_back(mq.max());
                mq.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums, k);

    return 0;
}
