//
// Created by Ehsan Kabeer on 5/7/25.
//

#include <iostream>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <typename valueType>
class linkedList {
private:
    struct Node {
        valueType val;
        Node* next;

        Node(const valueType& v): val(v), next(nullptr) {}
    };
    Node head;
    Node tail;
    size_t size;
public:
    Linkedlist() : head(), tail(), size(0) {}

    bool empty() {
        return size == 0;
    }
    size_t listSize() {
        return size;
    }

    valueType& front() {
        if (this->empty()) return nullptr;

        return head.val;
    }
    valueType& back() {
        if (this->empty()) return nullptr;

        return tail.val;
    }

    void pushFront(const valueType& v) {
        Node insertedNode(v);
        Node* oldHead = &head;



    }


};



#endif //LINKEDLIST_H
