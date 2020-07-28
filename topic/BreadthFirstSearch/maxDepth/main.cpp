/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
    // // BFS
    // int maxDepth(TreeNode* root) {
    //     if (!root) {
    //         return 0;
    //     }
    //     queue<TreeNode*> qu;
    //     int ans = 0;

    //     qu.push(root);
    //     while (!qu.empty()) {
    //         int len = qu.size();    // 记录当前层节点个数
    //         for (int i = 0; i < len; ++i) {
    //             TreeNode * tmp = qu.front();
    //             qu.pop();
    //             if (tmp->left) {
    //                 qu.push(tmp->left);
    //             }
    //             if (tmp->right) {
    //                 qu.push(tmp->right);
    //             }
    //         }
    //         ++ans;  // 记录二叉树深度
    //     }

    //     return ans;
    // }

    // 递归法
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class BiTree {
 public:
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
    string nodeList{"3,9,20,null,null,15,7,null,null,null,null"};
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodeList);

    Solution solution;
    int result = solution.maxDepth(root);
    cout << result << endl;

    return 0;
}
