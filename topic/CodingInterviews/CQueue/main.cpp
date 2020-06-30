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
#include <stack>

using namespace std;

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

class CQueue {
 public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }

    void appendTail(int value) {
        stack1.push(value);
    }

    // // 常规写法
    // int deleteHead() {
    //     if (stack2.empty()) {
    //         while (!stack1.empty()) {
    //             stack2.push(stack1.top());
    //             stack1.pop();
    //         }
    //     }
    //     if (stack2.empty()) {
    //         return -1;
    //     } else {
    //         int deleteItem = stack2.top();
    //         stack2.pop();
    //         return deleteItem;
    //     }
    // }

    int deleteHead() {
        if (!stack2.empty()) {
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        } else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            if (stack2.empty()) {
                return -1;
            } else {
                int deleteItem = stack2.top();
                stack2.pop();
                return deleteItem;
            }
        }
    }

 private:
    stack<int> stack1, stack2;
};

int main() {
    CQueue * obj = new CQueue();
    obj->appendTail(3);
    int param_2 = obj->deleteHead();
    int param_3 = obj->deleteHead();
    return 0;
}
