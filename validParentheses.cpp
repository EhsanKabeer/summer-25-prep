#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        stack<char> tracker;
        for (auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                tracker.push(c);
            }
            else {
                if(tracker.empty()){
                    return false;
                }
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
        return tracker.empty();
    }
};

int main() {
    cout << boolalpha;
    Solution test;
    string input = "(())";
    cout << test.isValid(input);

    return 0;
}