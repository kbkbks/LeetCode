/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
//     /**
//      * 暴力求解(枚举宽)
//      */
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int res = 0;
//         for (int i = 0; i < n; ++i) {
//             int minHeight = INT_MAX;
//             for (int j = i; j < n; ++j) {
//                 minHeight = min(minHeight, heights[j]);
//                 res = max(res, (j - i + 1) * minHeight);
//             }
//         }
//         return res;
//     }
// };

//     /**
//      * 暴力求解(枚举高)
//      */
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int res = 0;
//         for (int mid = 0; mid < n; ++mid) {
//             int left = mid, right = mid;
//             int height = heights[mid];
//             while (left - 1 >= 0 && heights[left - 1] >= height) --left;
//             while (right + 1 < n && heights[right + 1] >= height) ++right;
//             res = max(res, (right - left + 1) * height);
//         }
//         return res;
//     }

    /**
     * 单调栈+哨兵
     */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = mono_stack.empty() ? n : mono_stack.top();
            mono_stack.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;
    }
};

int main() {
    vector<int> heights{2, 1, 5, 6, 2, 3};
    Solution solution;
    int result = solution.largestRectangleArea(heights);

    return 0;
}
