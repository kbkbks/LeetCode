/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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
        for (int i = 1; i < nodelist.size(); ++i) {
            ListNode * pNewNode = new ListNode(nodelist[i]);
            p->next = pNewNode;
            p = pNewNode;
        }
    }

    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode * ans;

        return ans;
    }
};

int main() {
    vector<int> nodelist{1, 2, 3, 3, 2, 1};
    Solution solution;
    ListNode * head = new ListNode(nodelist[0]);
    solution.createList(head, nodelist);
    ListNode * result = solution.removeDuplicateNodes(head);

    return 0;
}
