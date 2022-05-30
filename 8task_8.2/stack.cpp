//
// Created by ssaha on 31.05.2022.
//

#include "stack.h"
void stack::push_back(int val) {
    if(size_stack > first) {
        Node* p = new Node(val);
        p->next = last;
        last = p;
        ++first;
    }
}

bool stack::is_empty() {
    return first == 0;
}

void stack::print() {
    if (is_empty()) return;
    Node* p = last;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

Node* stack::get() {
    if (!is_empty()) {
        Node *p = last;
        last = last->next;
        first--;
        return p;
    }
}

bool stack::fullstack(){return first == size_stack;}
int stack::can_we_see_the_buildings()
{
    if (is_empty()) return -1;
    Node* p = last;
    bool t = true;
    Node* copy = p->next;
    int i = 1;
    while (copy != nullptr) {
        if(p->val > copy->val){
            i++;
            t = false;
        }
        else if (t == false) {
            i--;
            t = true;
        }
        p = p->next;
        copy = p->next;
    }
    return i;
}
