//
// Created by ssaha on 31.05.2022.
//
#include "array.h"
#include <iostream>
using namespace std;

void array::push_back(int val) {
    NodeArray* p = new NodeArray(val);
    if (is_empty()) {
        first = p;
        last = p;
    }
    else {
        last->next = p;
        last = p;
    }
}

bool array::is_empty() {
    return first == nullptr;
}
void array::print() {
    if (is_empty()) return;
    NodeArray* p = first;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
NodeArray* array::find(int val) {
    NodeArray* p = first;
    while (p and p->val != val)
        p = p->next;
    if(p and p->val == val)
        return p;
    else
        return nullptr;
}

int array::operator[] (int index) {
    if (is_empty()) return -1;
    NodeArray* p = first;
    int i=0;
    for (i; i < index+1; i++) {
        if(index == i) return p->val;
        p = p->next;
        if (!p) return -1;
    }
    return i;
}
int array::size()
{
    int index = 0;
    NodeArray* p = first;
    while (p != nullptr)
    {
        index++;
        p = p->next;
    }
    return index;
}

int array::can_we_see_the_buildings(array l) {
    int max=0;
    int colm = 0;
    for(int i = 0;i<l.size();i++){
        if(max < l[i]) {
            max = l[i];
            colm++;
        }
    }
    if(l.size() == 1) return colm = 1;
    else return colm;
}

