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
    Node* head;
    Node* tail;
    size_t size;
public:
    linkedList() : head(), tail(), size(0) {}

    bool empty() {
        return size == 0;
    }
    size_t listSize() {
        return size;
    }

    valueType& front() {
        if (this->empty()) return nullptr;

        return head->val;
    }
    valueType& back() {
        if (this->empty()) return nullptr;

        return tail->val;
    }

    void pushFront(const valueType& v) {
        Node* insertedNode = new Node(v);
        if (this->empty()) {
            head = insertedNode;
            tail = head;
        }
        else {
            insertedNode->next = head;
            head = insertedNode;
        }
        size++;
    }
    void pushBack(const valueType& v) {
        Node* insertedNode = new Node(v);
        if (this->empty()) {
            head = tail = insertedNode;
        }
        else {
            tail->next = insertedNode;
            tail = insertedNode;
        }
        size++;
    }

    void pop_front () {
        if (empty()) return;
        Node* newHead = head->next;
        delete head;
        head = newHead;
        if (!head) tail = nullptr;
        size--;
    }
    void pop_back () {
        if (empty()) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size--;
        }
        else {
            Node* curr = head;
            while (curr != tail) {
                curr = curr->next;
            }
            delete tail;
            tail = curr;
            tail->next = nullptr;
            size--;
        }
    }
    bool remove(const valueType& value) {
        if (empty()) {
            return false;
        }
        if (head->val == value) {
            pop_front();
            return true;

        }
        Node* nodeRemoving = head->next;
        auto curr = head;
        while (nodeRemoving != nullptr) {
            if (nodeRemoving->val == value && tail == nodeRemoving) {
                pop_back();
                return true;

            }
            else if (nodeRemoving->val == value) {
                curr->next = nodeRemoving->next;
                delete nodeRemoving;
                size--;
                return true;
            }
            curr = nodeRemoving;
            nodeRemoving = curr->next;
        }
        return false;

    }
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // lookup
    Node* find(const valueType& value) const {
        auto curr = head;
        while (curr != nullptr) {
            if (curr->val == value) {
                return curr;
            }
            else {
                curr = curr->next;
            }
        }
        return nullptr;
    }


};



#endif //LINKEDLIST_H
