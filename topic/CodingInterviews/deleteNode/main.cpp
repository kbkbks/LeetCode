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
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) return nullptr;
        if (head->val == val) return head->next;
        ListNode * node = head;
        while (node->next!= nullptr) {
            if (node->next->val != val) {
                node = node->next;
            } else if (node->next->val == val) {
                node->next = node->next->next;
                break;
            }
        }

        return head;
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
    vector<int> nums{4, 5, 1, 9};
    int target = 5;
    LinkedList linkedlist;
    ListNode * head = linkedlist.createList(nums);
    Solution solution;
    ListNode * result = solution.deleteNode(head, target);

    return 0;
}
