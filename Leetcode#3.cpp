#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        //sliding window
        int start = 0;
        int end = 0;
        int BiggestWindow = 1;

        vector<int> letters(128,0);
        letters[s[end]]++;
        end++;

        while (end < s.size()) {
            letters[static_cast<int>(s[end])]++;
            if (letters[static_cast<int>(s[end])] > 1) {
                while (letters[static_cast<int>(s[end])] > 1) {
                    letters[static_cast<int>(s[start])]--;
                    start++;
                }
                end++;
            }
            else {
                BiggestWindow = max(BiggestWindow,end - start + 1);
                end++;
            }


            
        }
        return BiggestWindow;
    }

};


int main() {
    Solution test;
    cout << test.lengthOfLongestSubstring("dvdf");

    return 0;
}