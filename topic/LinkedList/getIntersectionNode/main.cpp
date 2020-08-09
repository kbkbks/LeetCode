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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * curA = headA;
        ListNode * curB = headB;
        while (curA != curB) {
            curA = curA != nullptr ? curA->next : headB;
            curB = curB != nullptr ? curB->next : headA;
        }
        return curA;
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
    /**
     * 尚未创建有公共节点的双链表
     */

    return 0;
}
