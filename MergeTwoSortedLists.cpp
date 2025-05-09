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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = nullptr;


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