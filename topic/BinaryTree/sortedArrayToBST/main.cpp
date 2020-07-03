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
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
 public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right) / 2;

        TreeNode * root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }

    // 中序遍历，总是选择中间位置左边的数字作为根节点
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    void Delete(TreeNode *& node) {
        if (node) {
            Delete(node->left);
            Delete(node->right);
            delete node;
        }
    }

    void newDelete(TreeNode * node) {
        if (node->left) {
            newDelete(node->left);
        }
        if (node->right) {
            newDelete(node->right);
        }
        delete node;
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
};

int main() {
    // TreeNode * root;
    // BiTree biTree;
    // biTree.create_BTree(root);

    vector<int> nums{-10, -3, 0, 5, 9};

    Solution solution;
    TreeNode * result = solution.sortedArrayToBST(nums);
    solution.newDelete(result);

    return 0;
    // biTree.Delete(root);
}
