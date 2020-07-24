/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
 public:
    // 递归
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> ans;

        // 枚举根节点
        for (int i = start; i <= end; ++i) {
            // 左子树
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            // 右子树
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto &left : leftTrees) {
                for (auto &right : rightTrees) {
                    TreeNode * current = new TreeNode(i);
                    current->left = left;
                    current->right = right;
                    ans.emplace_back(current);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }

 private:
    // vector<TreeNode*> ans;
};

int main() {
    int n = 3;
    Solution solution;
    vector<TreeNode*> result = solution.generateTrees(n);

    return 0;
}
