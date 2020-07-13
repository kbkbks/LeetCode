/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
    void createList(ListNode * head, vector<int> nodelist) {
        ListNode * p = head;
        for (int i = 0; i < nodelist.size(); ++i) {
            ListNode * pNewNode = new ListNode(nodelist[i]);
            p->next = pNewNode;
            p = pNewNode;
        }
    }

    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head) {
            return head;
        }
        unordered_set<int> set{head->val};
        ListNode * pos = head;
        while (pos->next) {
            ListNode * cur = pos->next;
            if (!set.count(cur->val)) {
                set.insert(cur->val);
                pos = pos->next;
            } else {
                pos->next = pos->next->next;
            }
        }
        pos->next = nullptr;
        return head;
    }
};

int main() {
    vector<int> nodelist{1, 2, 3, 3, 2, 1};
    Solution solution;
    ListNode * head = new ListNode(0);
    solution.createList(head, nodelist);
    ListNode * result = solution.removeDuplicateNodes(head);

    return 0;
}
