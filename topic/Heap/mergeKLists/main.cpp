/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <queue>

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
    struct Status {
        int val;
        ListNode * ptr;
        // Functional比较方式，小根堆
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    void createList(ListNode * head, vector<int> xLists) {
        ListNode * p = head;
        for (auto &x : xLists) {
            ListNode * pNewNode = new ListNode(x);
            p->next = pNewNode;
            p = pNewNode;
        }
    }

    // ListNode * mergeTwoLists(ListNode * a, ListNode * b) {
    //     if ((!a) || (!b)) {
    //         return a ? a : b;
    //     }

    //     ListNode head(0);
    //     ListNode * tail = &head;
    //     ListNode * aPtr = a, * bPtr = b;
    //     while (aPtr && bPtr) {
    //         if (aPtr->val < bPtr->val) {
    //             tail->next = aPtr;
    //             aPtr = aPtr->next;
    //         } else {
    //             tail->next = bPtr;
    //             bPtr = bPtr->next;
    //         }
    //         tail = tail->next;
    //     }
    //     tail->next = (aPtr ? aPtr : bPtr);

    //     return head.next;
    // }

    // // 暴力合并（顺序合并）
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode * ans = nullptr;
    //     for (size_t i = 0; i < lists.size(); ++i) {
    //         ans = mergeTwoLists(ans, lists[i]);
    //     }

    //     return ans;
    // }

    // // 分治合并
    // ListNode * merge(vector<ListNode*>& lists, int l, int r) {
    //     if (l == r) {
    //         return lists[l];
    //     }
    //     if (l > r) {
    //         return nullptr;
    //     }
    //     int mid = (l + r) / 2;
    //     return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    // }
    // // 分治合并
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     return merge(lists, 0, lists.size() - 1);
    // }

    // 优先队列合并（小根堆）
    ListNode * mergeKLists(vector<ListNode*>& lists) {
        for (auto pnode : lists) {
            if (pnode) {
                qu.push({pnode->val, pnode});
            }
        }
        ListNode head(0);
        ListNode *tail = &head;
        while (!qu.empty()) {
            auto tmp = qu.top();
            qu.pop();
            tail->next = tmp.ptr;
            tail = tail->next;
            if (tmp.ptr->next) {
                qu.push({tmp.ptr->next->val, tmp.ptr->next});
            }
        }
        return head.next;
    }

 private:
    priority_queue<Status> qu;
};

int main() {
    ListNode * head1 = new ListNode(1);
    vector<int> xLists1{4, 5};
    ListNode * head2 = new ListNode(1);
    vector<int> xLists2{3, 4};
    ListNode * head3 = new ListNode(2);
    vector<int> xLists3{6};

    Solution solution;
    solution.createList(head1, xLists1);
    solution.createList(head2, xLists2);
    solution.createList(head3, xLists3);
    vector<ListNode*> lists{head1, head2, head3};

    ListNode * result = solution.mergeKLists(lists);

    return 0;
}
