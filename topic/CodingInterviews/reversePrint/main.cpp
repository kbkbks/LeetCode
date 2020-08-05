/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 栈方法
     */
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> stk;
        vector<int> ans;
        ListNode * current = head;
        while (current != nullptr) {
            stk.push(current);
            current = current->next;
        }
        while (stk.size()) {
            ListNode * tmp = stk.top();
            stk.pop();
            ans.push_back(tmp->val);
        }

        return ans;
    }
};


/**
 * 主函数未完成，链表未生成
 */
int main() {
    vector<int> nums{1, 2, 3, 4};
    Solution solution;
    // vector<int> result = solution.reversePrint(nums);

    return 0;
}
