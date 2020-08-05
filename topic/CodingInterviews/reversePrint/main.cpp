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
 * 创建单链表
 */
class LinkedList {
 public:
    ListNode * createList(vector<int> nums) {
        ListNode * head = new ListNode(nums[0]);
        ListNode * p = head;
        for (int node = 1; node < nums.size(); ++node) {
            ListNode * pnode = new ListNode(nums[node]);
            p->next = pnode;
            p = pnode;
        }
        return head;
    }
};

int main() {
    vector<int> nums{1, 3, 2};
    LinkedList linkedlist;
    ListNode * head = linkedlist.createList(nums);
    Solution solution;
    vector<int> result = solution.reversePrint(head);

    return 0;
}
