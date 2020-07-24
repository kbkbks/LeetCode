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
    vector<TreeNode*> generateTrees(int n) {
        TreeNode * root = new TreeNode();
    }

    

 private:
    vector<TreeNode*> ans;
};

int main() {
    int n = 3;
    Solution solution;
    vector<TreeNode*> result = solution.generateTrees(n);

    return 0;
}
