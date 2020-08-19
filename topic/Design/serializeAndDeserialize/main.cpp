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

class Codec {
 private:
    string levelOrderSerialize(TreeNode * root) {
        if (!root) return {};

        queue<TreeNode*> qu;
        string res;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode * node = qu.front();
            qu.pop();
            if (node) {
                res += to_string(node->val) + ",";
                qu.push(node->left);
                qu.push(node->right);
            } else {
                res += "null,";
            }
        }
        return res;
    }

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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return levelOrderSerialize(root);
    }

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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    // string nodeList{"1,null,2,null,null,null,3,null,null,null,null,null,null,null,4"};   // 该为BalanceBST中的反序列化格式，null多
    string nodeList{"1,null,2,null,3,null,4"};  // 该为leetcode标准的反序列化格式，null少
    Codec codec;
    TreeNode * result = codec.deserialize(nodeList);
    string ans = codec.serialize(result);
    cout << ans << endl;

    return 0;
}
