#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {}

    void push_back(int val) {
        Node* p = new Node(val);
        if (is_empty()) {
            first = p;
            last = p;
        }
        else {
            last->next = p;
            last = p;
        }
    }

    bool is_empty() {
        return first == nullptr;
    }
    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    Node* find(int val) {
        Node* p = first;
        while (p and p->val != val)
            p = p->next;
        if(p and p->val == val)
            return p;
        else
            return nullptr;
    }

    int operator[] (int index) {
        if (is_empty()) return -1;
        Node* p = first;
        int i=0;
        for (i; i < index+1; i++) {
            if(index == i) return p->val;
            p = p->next;
            if (!p) return -1;
        }
        return i;
    }
    int size()
    {
        int index = 0;
        Node* p = first;
        while (p != nullptr)
        {
            index++;
            p = p->next;
        }
        return index;
    }
};

int main() {
    list l1;
    list l2;
    list l;
    cout << l.is_empty() << endl;
    for(int i = 0;i<10;i++) {
        l1.push_back(1 + rand() % 100);
        l2.push_back(1 + rand() % 100);
    }

    for(int i = 0;i<l1.size();i++){
        if(l2.find(l1[i]) == nullptr)
            l.push_back(l1[i]);
    }
    cout << l.is_empty() << endl;
    cout<<"l"<<" ";
    l.print();
    cout<<"l2"<<" ";
    l2.print();
    cout<<"l1"<<" ";
    l1.print();
    return 0;
}