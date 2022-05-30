//
// Created by ssaha on 31.05.2022.
//

#ifndef INC_7_1_ARRAY_H
#define INC_7_1_ARRAY_H
#include "NodeArray.h"
struct array {
    NodeArray* first;
    NodeArray* last;
    array() : first(nullptr) , last(nullptr) {}
    void push_back(int val);
    bool is_empty();
    NodeArray* find(int val);
    void print();
    int operator[] (int index);
    int size();
    int can_we_see_the_buildings(array l);
};
#endif //INC_7_1_ARRAY_H
