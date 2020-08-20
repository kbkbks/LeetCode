/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
    vector<vector<int>> res;

    void dfs(TreeNode * node, int target, vector<int> &path) {
        if (!node) return;

        path.push_back(node->val);
        if (!node->left && !node->right && node->val == target) {
            res.push_back(path);
        }
        dfs(node->left, target - node->val, path);
        dfs(node->right, target - node->val, path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<int> path;
        dfs(root, sum, path);
        return res;
    }
};

class Codec {
 private:
    TreeNode * deLevelOrder(vector<TreeNode*> input) {
        int child = 1;
        for (int parent = 0; child < input.size(); ++parent) {
            if (input[parent] == nullptr) continue;
            if (child < input.size()) {
                input[parent]->left = input[child];
                child++;
            }
            if (child < input.size()) {
                input[parent]->right = input[child];
                child++;
            }
        }
        return input[0];
    }

 public:
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<TreeNode*> input;
        stringstream ss(data);
        string tmp;
        while (getline(ss, tmp, ',')) {
            if (tmp == "null") {
                input.push_back(nullptr);
            } else {
                input.push_back(new TreeNode(stoi(tmp)));
            }
        }
        return deLevelOrder(input);
    }
};

int main() {
    string nodeList{"5,4,8,11,null,13,4,7,2,null,null,5,1"};
    int sum = 22;
    Codec codec;
    TreeNode * root = codec.deserialize(nodeList);
    Solution solution;
    vector<vector<int>> result = solution.pathSum(root, sum);

    return 0;
}
