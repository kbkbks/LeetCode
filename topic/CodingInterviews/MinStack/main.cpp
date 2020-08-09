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

class MinStack {
 public:
    stack<int> stack1, stack2;
    /** initialize your data structure here. */
    MinStack() { }

    void push(int x) {
        stack1.push(x);
        if (stack2.empty() || x <= stack2.top()) stack2.push(x);
    }

    void pop() {
        if (!stack1.empty()) {
            if (stack1.top() == stack2.top()) stack2.pop();
            stack1.pop();
        }
    }

    int top() {
        return stack1.top();
    }

    int min() {
        return stack2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.min();
    minStack.pop();
    minStack.top();
    minStack.min();

    return 0;
}
