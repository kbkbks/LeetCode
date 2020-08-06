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

/**
 * 新的建树类
 */
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
        vector<string> input;
        stringstream ss(nodeList);
        string tmp;
        while (getline(ss, tmp, ',')) {
            input.push_back(tmp);
        }

        return buildTree(input, 0);
    }

    TreeNode * buildTree(const vector<string> &input, int start) {
        if (start > input.size() - 1 || input[start] == "null") {
            return nullptr;
        }

        TreeNode * node = new TreeNode(stoi(input[start]));
        int leftNode = start * 2 + 1;
        int rightNode = start * 2 + 2;
        node->left = buildTree(input, leftNode);
        node->right = buildTree(input, rightNode);
        return node;
    }

    // 层序遍历
    vector<vector<int>> levelOrder(TreeNode * root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            vector<int> tmpLevel;
            int n = qu.size();
            for (int i = 0; i < n; ++i) {
                TreeNode * node = qu.front();
                qu.pop();
                tmpLevel.push_back(node->val);
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            ans.push_back(tmpLevel);
        }

        return ans;
    }
};

int main() {
    // string常规建树
    string nodeList{"3,2,3,null,3,null,1"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);
    vector<vector<int>> levelPrint = biTree.levelOrder(root);

    // 打家劫舍
    Solution solution;
    int result = solution.rob(root);

    return 0;
}
