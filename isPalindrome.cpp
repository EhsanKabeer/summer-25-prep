#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>     // for std::isspace
using namespace std;

bool is_non_ascii(char c) {
    return static_cast<unsigned char>(c) <= '^';
}

class Solution {
public:

    bool isPalindrome(string s) {
        s.erase(
  std::remove_if(s.begin(), s.end(), is_non_ascii),
  s.end()
);
        cout << s;
        return false;
    }
};

int main() {
    Solution test;
    test.isPalindrome("A man, a plan, a canal: Panama");

}