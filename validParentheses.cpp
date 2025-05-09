#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tracker;
        for (auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                tracker.push(c);
            }
            else {
                if (c == ')' && tracker.top() == '(') {
                    tracker.pop();
                }
                else if (c == '}' && tracker.top() == '{') {
                    tracker.pop();
                }
                else if (c == ']' && tracker.top() == '[') {
                    tracker.pop();
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution test;
    string input = "()[{}]";
    if (test.isValid(input)) {
        cout << "Correct solution!\n";
    }

    return 0;
}