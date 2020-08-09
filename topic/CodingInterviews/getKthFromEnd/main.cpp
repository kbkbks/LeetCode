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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode * pre = head;
        ListNode * post = head;
        for (int i = 0; i < k; ++i) {
            pre = pre->next;
        }
        while (pre != nullptr) {
            post = post->next;
            pre = pre->next;
        }

        return post;
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
    vector<int> nums{1, 2, 3, 4, 5};
    int target = 3;
    LinkedList linkedlist;
    ListNode * head = linkedlist.createList(nums);
    Solution solution;
    ListNode * result = solution.getKthFromEnd(head, target);

    return 0;
}
