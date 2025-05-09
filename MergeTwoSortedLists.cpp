#include <iostream>
#include <list>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = nullptr;
        if (list1 == nullptr && list2 == nullptr) {
            return newHead;
        }
        if (list1 == nullptr && list2 != nullptr) {
            return list2;
        }
        if (list2 == nullptr && list1 != nullptr){
            return list1;
        }

        if (list1->val >= list2->val) {
            newHead = list2;
            list2 = list2->next;
        }
        else {
            newHead = list1;
            list1 = list1->next;
        }
        ListNode* prev = nullptr;
        auto curr = newHead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val >= list2->val) {
                curr->next = list2;
                prev = curr;
                curr = curr->next;
                list2 = list2->next;
            }
            else {
                curr->next = list1;
                prev = curr;
                curr = curr->next;
                list1 = list1->next;
            }
        }
        if (!list1) {
            curr->next = list2;
        }
        else if (!list2) {
            curr->next = list1;
        }
        return newHead;

    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* b1 = new ListNode(2);
    ListNode* c1 = new ListNode(4);

    head1->next = b1;
    b1->next = c1;

    ListNode* head2 = new ListNode(1);
    ListNode* b2 = new ListNode(3);
    ListNode* c2 = new ListNode(4);

    head2->next = b2;
    b2->next = c2;

    Solution test;
    auto mergedHead = test.mergeTwoLists(head1,head2);

    while (mergedHead) {
        cout << mergedHead << ' ';
    }
    cout << '\n';


    return 0;


}