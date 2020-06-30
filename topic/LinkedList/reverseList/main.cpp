/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
    ListNode* reverseList(ListNode* head) {
        ListNode * pre = NULL;
        ListNode * cur = head;
        ListNode * tmp = NULL;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main() {
    return 0;
}
