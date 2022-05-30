//
// Created by ssaha on 31.05.2022.
//

#ifndef INC_7_1_NODEARRAY_H
#define INC_7_1_NODEARRAY_H
#include <iostream>
using namespace std;

struct NodeArray {
    int val;
    NodeArray* next;
    NodeArray(int val) : val(val), next(nullptr) {}
};
#endif //INC_7_1_NODEARRAY_H
