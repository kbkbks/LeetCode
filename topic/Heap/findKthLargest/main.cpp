/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
 public:
    // // 排序函数
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     reverse(nums.begin(), nums.end());

    //     return nums[k - 1];
    // }

    // 最大堆排序
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int leftChild = i * 2 + 1;
        int rightChild = i *2 + 2;
        int largest = i;
        if (leftChild < heapSize && a[leftChild] > a[largest]) {
            largest = leftChild;
        }
        if (rightChild < heapSize && a[rightChild] > a[largest]) {
            largest = rightChild;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }

        return nums[0];
    }
};

int main() {
    vector<int> nums{3,2,1,5,6,4};
    int k{2};

    Solution solution;
    int result = solution.findKthLargest(nums, k);
    cout << result << endl;

    return 0;
}
