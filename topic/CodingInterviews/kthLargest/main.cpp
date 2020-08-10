/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
    vector<int> res;

    void dfs(TreeNode * node) {
        if (!node) return;
        dfs(node->right);
        res.push_back(node->val);
        dfs(node->left);
    }

    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        return res[k - 1];
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
};

int main() {
    // string常规建树
    string nodeList{"3,1,4,null,2"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);
    int k = 1;

    // 将二叉树变平衡
    Solution solution;
    int result = solution.kthLargest(root, k);

    return 0;
}
