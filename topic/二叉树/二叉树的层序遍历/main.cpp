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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(!root) 
            return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            vector<int> tmp;
            int len = qu.size();
            for(int i = 0; i < len; ++i)
            {
                TreeNode* node = qu.front();
                qu.pop();
                tmp.push_back(node->val);
                if(node->left)
                    qu.push(node->left);
                if(node->right)
                    qu.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }

};

class BiTree
{
public:
    void create_BTree(TreeNode *& node)
    {
        string data;
        cout << "请输入结点：" << endl;
        cin >> data;
        string check = {"null"};
        //结点不存在
        if(data == check)
        {
            node = NULL;
            cout << "结点不存在" << endl; 
        }
        else
        {
            node = new TreeNode(stoi(data));
            cout << "当前结点为" << node->val << endl; 
            create_BTree(node->left);
            cout << "当前结点为" << node->val << endl; 
            create_BTree(node->right);
        }
    }

    void Delete(TreeNode *& node)
    {
        if(node)
        {
            Delete(node->left);
            Delete(node->right);
            delete node;
        }
    }

};


int main()
{
    TreeNode * root;
    BiTree biTree;
    biTree.create_BTree(root);

    Solution solution;
    solution.levelOrder(root);

    biTree.Delete(root);

}