#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tracker;
        for (auto& c : s) {
            tracker.push(c);
        }

    }
};

int main() {
    Solution test;
    string input = "()";
    if (test.isValid(input)) {
        cout << "Correct solution!\n";
    }

    return 0;
}