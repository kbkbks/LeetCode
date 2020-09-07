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
    explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        ListNode * fast = head;
        ListNode * slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

int main() {
    // 未建立具体环形链表，故无主程序

    return 0;
}
