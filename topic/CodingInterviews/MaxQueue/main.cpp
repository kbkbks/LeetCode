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

class MaxQueue {
    queue<int> qu;
    deque<int> dq;

 public:
    MaxQueue() { }

    int max_value() {
        if (dq.empty()) {
            return -1;
        }

        return dq.front();
    }

    void push_back(int value) {
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }
        dq.push_back(value);
        qu.push(value);
    }

    int pop_front() {
        if (dq.empty()) return -1;
        int ans = qu.front();
        if (dq.front() == ans) dq.pop_front();
        qu.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {
    MaxQueue * obj = new MaxQueue();
    int param_1 = obj->max_value();
    obj->push_back(1);
    int param_3 = obj->pop_front();

    return 0;
}
