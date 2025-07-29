#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        return helper("",digits);
    }

private:
    vector<string> helper(string p,string up) {
        if (up.empty()) {
            vector<string> temp;
            temp.push_back(p);
            return temp;
        }

        vector<string> combinations;
        int num = stoi(up.substr(0,1));

        if (num == 7) {
            for (int i = 15;i <= 18;i++) {
                char ch = static_cast<char>('a' + i);
                vector<string> currIter = helper(p + ch,up.substr(1));
                combinations.insert(combinations.end(),currIter.begin(),currIter.end());
            }
        }
        else if (num == 8) {
            for (int i = 19;i < 22;i++) {
                char ch = static_cast<char>('a' + i);
                vector<string> currIter = helper(p + ch,up.substr(1));
                combinations.insert(combinations.end(),currIter.begin(),currIter.end());
            }
        }
        else if (num == 9) {
            for (int i = 22;i < 26;i++) {
                char ch = static_cast<char>('a' + i);
                vector<string> currIter = helper(p + ch,up.substr(1));
                combinations.insert(combinations.end(),currIter.begin(),currIter.end());
            }
        }
        else {
            for (int i = (num - 2) * 3;i < (num - 1) * 3;i++) {
                char ch = static_cast<char>('a' + i);
                vector<string> currIter = helper(p + ch,up.substr(1));
                combinations.insert(combinations.end(),currIter.begin(),currIter.end());
            }
        }
        return combinations;


    }
};


int main() {
    Solution test;
    vector <string> testOut = test.letterCombinations("7524");

    return 0;
}