//
// Created by ssaha on 31.05.2022.
//
#ifndef INC_7_1_STACK_H
#define INC_7_1_STACK_H
#include "Node.h"
#include <iostream>
using namespace std;
struct stack {
    int first;
    Node* last;
    int size_stack;
    stack(int size) : first(0), last(nullptr), size_stack(size) {}
    void push_back(int val);
    bool is_empty();
    void print();
    Node *get();
    bool fullstack();
    int can_we_see_the_buildings();
};
#endif //INC_7_1_STACK_H
