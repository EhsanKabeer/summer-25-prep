#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();

        int longestLength = 1;
        char* curr = &s[0];
        char* next = &s[1];

        int currLength = 1;
        for (int i = 1;i < s.length();i++) {
            if (*curr == *next) {
                curr = next++;
                if (currLength > longestLength) {
                    longestLength = currLength;
                }
                currLength = 1;
            }
            else {
                currLength++;
                curr = next++;
            }
            if (next == &s.back()) {
                if (*curr != *next) {
                    currLength++;
                }
                if (currLength > longestLength) {
                    longestLength = currLength;
                }
                break;
            }
        }

        return longestLength;
        
    }
};


int main() {
    Solution test;
    cout << test.lengthOfLongestSubstring("hhelillo");

    return 0;
}