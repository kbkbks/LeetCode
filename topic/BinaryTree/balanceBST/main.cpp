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
    // 中序遍历
    void getInorder(TreeNode * node) {
        if (!node) {
            return;
        }

        if (node->left) {
            getInorder(node->left);
        }
        inorderSeq.push_back(node->val);
        if (node->right) {
            getInorder(node->right);
        }
    }

    // 贪心构造
    TreeNode * build(int leftSide, int rightSide) {
        int mid = (leftSide + rightSide) / 2;
        TreeNode * node = new TreeNode(inorderSeq[mid]);
        if (leftSide <= mid - 1) {
            node->left = build(leftSide, mid - 1);
        }
        if (mid + 1 <= rightSide) {
            node->right = build(mid + 1, rightSide);
        }
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }

 private:
    vector<int> inorderSeq;
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
    string nodeList{"1,null,2,null,null,null,3,null,null,null,null,null,null,null,4"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);

    // 将二叉树变平衡
    Solution solution;
    TreeNode * result = solution.balanceBST(root);

    biTree.Delete(root);
    biTree.Delete(result);
    return 0;
}
