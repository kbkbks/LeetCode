/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct Node {
    int val;
    Node *left;
    Node *right;
    explicit Node(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node* head = nullptr, *tail = nullptr;
        helper(root, head, tail);
        head->left = tail;
        tail->right = head;
        return head;
    }

    void helper(Node * node, Node *& head, Node *& tail) {
        if (!node) return;
        helper(node->left, head, tail);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->right = node;
            node->left = tail;
            tail = node;
        }
        helper(node->right, head, tail);
    }
};

class Codec {
 private:
    Node * deLevelOrder(vector<Node*> input) {
        int child = 1;
        for (int parent = 0; child < input.size(); ++parent) {
            if (input[parent] == nullptr) continue;
            if (child < input.size()) {
                input[parent]->left = input[child];
                child++;
            }
            if (child < input.size()) {
                input[parent]->right = input[child];
                child++;
            }
        }
        return input[0];
    }

 public:
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<Node*> input;
        stringstream ss(data);
        string tmp;
        while (getline(ss, tmp, ',')) {
            if (tmp == "null") {
                input.push_back(nullptr);
            } else {
                input.push_back(new Node(stoi(tmp)));
            }
        }
        return deLevelOrder(input);
    }
};

int main() {
    string nodeList{"4, 2, 5, 1, 3"};  // 该为leetcode标准的反序列化格式，null少
    Codec codec;
    Node * root = codec.deserialize(nodeList);

    Solution solution;
    Node * head = solution.treeToDoublyList(root);
    return 0;
}
