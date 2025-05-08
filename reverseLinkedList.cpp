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
        if (!head) {
            return nullptr;
        }
        else if (head->next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        auto curr = head;
        auto next = head->next;
        while (curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != nullptr) {
                next = next->next;
            }
        }
        return prev;
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

    ListNode* printing = head;
    while (printing != nullptr) {
        cout << printing->val << " ";
        printing = printing->next;
    }
    cout << '\n';

    Solution testFunc;
    auto newHead = testFunc.reverseList(head);
    printing = newHead;
    while (printing != nullptr) {
        cout << printing->val;
        printing = printing->next;
    }

    return 0;
}