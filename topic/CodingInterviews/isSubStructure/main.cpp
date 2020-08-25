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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool helper(TreeNode * A, TreeNode * B) {
        if (!A || !B) {
            return B == nullptr ? true : false;
        }
        if (A->val != B->val) return false;
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
};

class Codec {
 private:
    TreeNode * deLevelOrder(vector<TreeNode*> input) {
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
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<TreeNode*> input;
        stringstream ss(data);
        string tmp;
        while (getline(ss, tmp, ',')) {
            if (tmp == "null") {
                input.push_back(nullptr);
            } else {
                input.push_back(new TreeNode(stoi(tmp)));
            }
        }
        return deLevelOrder(input);
    }
};

int main() {
    string nodeList1{"3,4,5,1,2"};
    string nodeList2{"4,1"};
    Codec codec;
    TreeNode * A = codec.deserialize(nodeList1);
    TreeNode * B = codec.deserialize(nodeList2);
    Solution solution;
    bool result = solution.isSubStructure(A, B);

    return 0;
}
