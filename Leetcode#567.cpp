#include <string>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        char* left = &s2[0];
        char* right = &s2[s1.length()];
        set<char> letters;
        for (auto curr : s1) {
            letters.emplace(curr);
        }
        return helper(left,right,letters);
    }
private:
    bool helper(char* left,char* right,set<char> letters) {
        auto tempLeft = left;
        while (tempLeft != right) {
            if (letters.contains(*tempLeft)) {
                tempLeft++;
            }
            else if (*right == '\0'){
                return false;
            }
            else {
                return helper(++left,++right,letters);
            }
        }
        return true;
    }
};

int main() {
    cout << std::boolalpha;
    string testStr = "eidboaoo";
    string testStr2 = "ab";

    Solution test;
    cout << test.checkInclusion(testStr2,testStr) << '\n';
    cout << testStr.substr(1);

    return 0;
}