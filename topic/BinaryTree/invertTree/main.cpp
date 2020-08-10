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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode * res = new TreeNode(root->val);
        res->right = invertTree(root->left);
        res->left = invertTree(root->right);
        return res;
    }
};

class BiTree {
 public:
    void create_BTree(TreeNode *& node) {
        string data;
        cout << "请输入结点：" << endl;
        cin >> data;
        string check = {"null"};
        //结点不存在
        if (data == check) {
            node = NULL;
            cout << "结点不存在" << endl;
        } else {
            node = new TreeNode(stoi(data));
            cout << "当前结点为" << node->val << endl;
            create_BTree(node->left);
            cout << "当前结点为" << node->val << endl;
            create_BTree(node->right);
        }
    }

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
    string nodeList{"4,2,7,1,3,6,9"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);

    // 将二叉树变平衡
    Solution solution;
    TreeNode * result = solution.invertTree(root);

    biTree.Delete(root);
    biTree.Delete(result);
    return 0;
}
