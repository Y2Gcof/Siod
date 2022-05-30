//
// Created by ssaha on 31.05.2022.
//

#ifndef INC_7_1_NODE_H
#define INC_7_1_NODE_H



struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr){};
};



#endif //INC_7_1_NODE_H
