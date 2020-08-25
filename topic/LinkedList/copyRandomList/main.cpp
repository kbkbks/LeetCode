/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
 public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
 public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> hashMap;
        Node * cur = head;
        while (cur) {
            hashMap[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            Node * node = hashMap[cur];
            node->next = hashMap[cur->next];
            node->random = hashMap[cur->random];
            cur = cur->next;
        }
        return hashMap[head];
    }
};

int main() {
    // 未建立RandomList
    return 0;
}
