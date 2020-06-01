/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
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
    // // 递归
    // bool checkSymmetric(TreeNode * p, TreeNode * q) {
    //     if (!p && !q) return true;
    //     if (!p || !q) return false;
    //     return p->val == q->val && checkSymmetric(p->left, q->right) && checkSymmetric(p->right, q->left);
    // }

    // 迭代
    bool checkSymmetric(TreeNode * p, TreeNode * q) {
        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);
        while (!qu.empty()) {
            p = qu.front();
            qu.pop();
            q = qu.front();
            qu.pop();
            if (!p && !q) continue;
            if ((!p || !q) || p->val != q->val) return false;
            qu.push(p->left);
            qu.push(q->right);
            qu.push(p->right);
            qu.push(q->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root, root);
    }
};

int main() {
    return 0;
}
