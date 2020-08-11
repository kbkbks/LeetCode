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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> dq;
        vector<vector<int>> res;
        bool flag = true;
        dq.push_back(root);
        while (!dq.empty()) {
            int n = dq.size();
            vector<int> tmp;
            for (int i = 0; i < n; ++i) {
                TreeNode * node;
                if (flag) {
                    node = dq.front();
                    dq.pop_front();
                    if (node) {
                        tmp.push_back(node->val);
                        dq.push_back(node->left);
                        dq.push_back(node->right);
                    }
                } else {
                    node = dq.back();
                    dq.pop_back(); 
                    if (node) {
                        tmp.push_back(node->val);
                        dq.push_front(node->right);
                        dq.push_front(node->left);
                    }                                      
                }
            }
            if (!tmp.empty()) res.push_back(tmp);
            flag = (flag == true)? false : true;
        }

        return res;
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
    string nodeList{"3,9,20,null,null,15,7"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);

    // 将二叉树变平衡
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    return 0;
}
