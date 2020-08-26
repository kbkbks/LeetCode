/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class MedianFinder {
    priority_queue<int> lo;     // 大顶堆
    priority_queue<int, vector<int>, greater<int> > hi;     // 小顶堆

 public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    /**
     * 两个堆方法
     */
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
    }


    // /**
    //  * 插入排序方法（二分查找插入元素）
    //  */
    // void addNum(int num) {
    //     if (store.empty()) {
    //         store.push_back(num);
    //     } else {
    //         store.insert(lower_bound(store.begin(), store.end(), num), num);
    //     }
    // }

    // double findMedian() {
    //     int n = store.size();
    //     double ans;
    //     if (n & 1) {
    //         ans = store[n / 2];
    //     } else {
    //         ans = (store[n / 2 - 1] + store[n / 2]) * 0.5;
    //     }
    //     return ans;
    // }

    // /**
    //  * 普通排序方法（超时）
    //  */
    // void addNum(int num) {
    //     store.push_back(num);
    // }
 
    // double findMedian() {
    //     double ans;
    //     sort(store.begin(), store.end());
    //     int n = store.size();
    //     if (n & 1) ans = store[n / 2];
    //     else ans = (store[n / 2 - 1] + store[n / 2]) * 0.5;
    //     return ans;
    // }
};

int main() {
    MedianFinder medianfinder;
    medianfinder.addNum(1);
    medianfinder.addNum(2);
    double ans1 = medianfinder.findMedian();
    medianfinder.addNum(3);
    double ans2 = medianfinder.findMedian();

    return 0;
}
