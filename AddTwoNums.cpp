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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = 0;
        int sum;
        ListNode* sumHead = nullptr;

        sum = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        if (sum > 9) {
            remainder = 1;
        }
        sumHead = new ListNode(sum % 10);
        auto curr = sumHead;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + remainder;
            l1 = l1->next;
            l2 = l2->next;
            if (sum > 9) remainder = 1;
            else remainder = 0;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        if (l1 != nullptr && l2 == nullptr) {
            while (l1 != nullptr) {
                sum = l1->val + remainder;
                l1 = l1->next;
                if (sum > 9) remainder = 1;
                else remainder = 0;

                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
        }
        else if (l1 == nullptr && l2 != nullptr) {
            while (l2 != nullptr) {
                sum = l2->val + remainder;
                l2 = l2->next;
                if (sum > 9) remainder = 1;
                else remainder = 0;

                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
        }
        if (remainder > 0) {
            curr->next = new ListNode(remainder);
            curr = curr->next;
        }
        return sumHead;
    }
};

int main() {
    auto h1 = new ListNode(9);
    auto b1 = new ListNode(9);
    auto c1 = new ListNode(9);

    auto h2 = new ListNode(9);
    auto b2 = new ListNode(9);
    auto c2 = new ListNode(9);

    h1->next = b1;
    b1->next = c1;

    h2->next = b2;
    b2->next = c2;

    Solution test;
    auto sum = test.addTwoNumbers(h1,h2);
    while (sum) {
        cout << sum->val << ' ';
        sum = sum->next;
    }
    cout << '\n';
    return 0;
}