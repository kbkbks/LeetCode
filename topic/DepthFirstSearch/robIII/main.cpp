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

struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution {
 public:
    unordered_map<TreeNode*, int> f, g;

    /**
     * 哈希 + dfs + dp + 后序遍历
     */

    // void dfs(TreeNode * o) {
    //     if (!o) {
    //         return;
    //     }
    //     dfs(o->left);
    //     dfs(o->right);
    //     f[o] = o->val + g[o->left] + g[o->right];
    //     g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
    // }

    // int rob(TreeNode *root){
    //     dfs(root);
    //     return max(f[root], g[root]);
    // }

    /**
     * 空间优化
     */
    SubtreeStatus dfs(TreeNode* o) {
        if (!o) {
            return {0, 0};
        }
        auto l = dfs(o->left);
        auto r = dfs(o->right);
        int selected = o->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode* o) {
        auto rootStatus = dfs(o);
        return max(rootStatus.selected, rootStatus.notSelected);
    }

};

class BiTree {
 public:
    void Delete(TreeNode *& node) {
        if (node) {
            Delete(node->left);
            Delete(node->right);
            delete node;
        }
    }

    TreeNode * creatTree(string nodeList) {
        // string格式化分割成vector<string>
        queue<string> input;
        stringstream ss(nodeList);
        string tmp;
        while (getline(ss, tmp, ',')) {
            input.push(tmp);
        }

        string node = input.front();
        input.pop();
        TreeNode * root;
        if (node != "null") {
            root = new TreeNode(stoi(node));
            string nodeLeft = input.front();
            input.pop();
            string nodeRignt = input.front();
            input.pop();
            root->left = buildTree(nodeLeft, input);
            root->right = buildTree(nodeRignt, input);
        } else {
            return nullptr;
        }
        return root;
    }

    TreeNode * buildTree(string node, queue<string> &input) {
        if (node != "null") {
            TreeNode * newNode = new TreeNode(stoi(node));
            string nodeLeft = input.front();
            input.pop();
            string nodeRignt = input.front();
            input.pop();
            newNode->left = buildTree(nodeLeft, input);
            newNode->right = buildTree(nodeRignt, input);
            return newNode;
        } else {
            return nullptr;
        }
    }
};

int main() {
    // string常规建树
    string nodeList{"3,2,3,null,3,null,1,null,null,null,null"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);

    // 打家劫舍
    Solution solution;
    int result = solution.rob(root);

    return 0;
}
