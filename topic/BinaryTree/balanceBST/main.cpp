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
    string nodeList{"1,null,2,null,3,null,4,null,null"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);

    // 将二叉树变平衡
    Solution solution;
    TreeNode * result = solution.balanceBST(root);

    biTree.Delete(root);
    biTree.Delete(result);
    return 0;
}
