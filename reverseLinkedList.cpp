#include <iostream>
#include <string>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        auto curr = head;
        auto next = head->next;


    }
};


int main() {
    ListNode* head = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);

    head->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Solution testFunc;
    auto newHead = testFunc.reverseList(head);


    return 0;
}