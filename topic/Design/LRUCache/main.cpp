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

using namespace std;

struct DlinkedNode {
    int key, value;
    DlinkedNode* prev;
    DlinkedNode* next;
    DlinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 public:
    explicit LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 伪头部和伪尾部
        head = new DlinkedNode();
        tail = new DlinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;

        // 如果key存在，先通过定位，再移动到头部
        DlinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果key不存在，则创建一个新节点
            DlinkedNode* node = new DlinkedNode(key, value);
            // 添加入hashmap
            cache[key] = node;
            // 添加至双向链表头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 超出容量，删除尾部节点
                DlinkedNode* removed = removeTail();
                // 删除hachmap中的对应项
                cache.erase(removed->key);
                --size;
            }
        } else {
            // 如果key存在，则选通过hashmap定位，再修改value，最后移动到头部
            DlinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DlinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DlinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DlinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DlinkedNode* removeTail() {
        DlinkedNode* node = tail->prev;
        removeNode(node);

        return node;
    }

 private:
    unordered_map<int, DlinkedNode*> cache;
    DlinkedNode* tail;
    DlinkedNode* head;
    int size;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    int result = cache.get(1);
    cout << result << endl;

    return 0;
}
