/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

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
    TreeNode * myBuildTree(const vector<int>& preorder, const vector<int>& inorder,
    int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 找到根节点(位置)
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点（位置）
        int inorder_root = index[preorder[preorder_root]];

        // 建立根节点
        TreeNode * root = new TreeNode(preorder[preorder_root]);
        // 求出左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归构造左子树，并连接到根节点
        root->left = myBuildTree(preorder, inorder, preorder_left + 1,
         preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归构造右子树，并连接到根节点
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1,
         preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index.insert(pair<int, int>(inorder[i], i));
        }

        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    void Delete(TreeNode *& node) {
        if (node) {
            Delete(node->left);
            Delete(node->right);
            delete node;
        }
    }

 private:
    unordered_map<int, int> index;
};

int main() {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution solution;
    TreeNode * tree = solution.buildTree(preorder, inorder);
    solution.Delete(tree);

    return 0;
}
