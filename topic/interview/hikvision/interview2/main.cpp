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

struct A {
    int i;
    A() { }
    A(const A& a):i(a.i){ }
    A operator+(const A& a) {
        A b;
        b.i = this->i + a.i;

        return b;
    }
    A& operator=(const A& rhs) {
       i = rhs.i;
       return *this;
    }
};

int main() {
    A a, b;
    a.i = 1;
    b.i = 2;
    A c = a + b;
    A d;
    d = a + c;
    
    return 0;
}

