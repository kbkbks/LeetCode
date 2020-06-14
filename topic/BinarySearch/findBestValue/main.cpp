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
 public :
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums{3, 1, 3, 3, 2};
    Solution solution;
    int result = solution.findDuplicate(nums);
    cout << result << endl;

    return 0;
}
