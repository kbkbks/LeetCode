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
#include <sstream>
#include <stack>

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
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
    string nodelist{"5,4,8,11,null,7,2,null,null,null,null,13,4,null,null,null,1,null,null"};
    const int SUM = 22;
    BiTree biTree;
    TreeNode * root = biTree.creatTree(nodelist);
    Solution solution;
    bool result = solution.hasPathSum(root, SUM);
    cout << result << endl;
    biTree.Delete(root);

    return 0;
}
