/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
    /**
     * 通用方法（适用所有二叉树）
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || root->val == p->val || root->val == q->val) return root;
       TreeNode * L = lowestCommonAncestor(root->left, p, q);
       TreeNode * R = lowestCommonAncestor(root->right, p, q);
       if (!L) return R;
       if (!R) return L;
       return root;
    }
};

class Codec {
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
    string nodeList{"3,5,1,6,2,0,8,null,null,7,4"};
    TreeNode * p = new TreeNode(6);
    TreeNode * q = new TreeNode(8);
    Codec codec;
    TreeNode * root = codec.deserialize(nodeList);

    Solution solution;
    TreeNode * result = solution.lowestCommonAncestor(root, p, q);

    return 0;
}
