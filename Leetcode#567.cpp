#include <string>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size() || s2.empty()) {
            return false;
        }
        else if (s1.empty()) return true;


        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        int x = s1.size(), y = s2.size();
        for (int i = 0; i < x;i++) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }

        if (hash2 == hash1) {
            return true;
        }

        for(int i = x;i < y;i++) {
            hash2[s2[i] - 'a']++;
            hash2[s2[i-x] - 'a']--;
            if (hash1 == hash2) return true;
        }
        return false;

    }
private:

};

int main() {
    cout << std::boolalpha;
    string testStr = "ehsankaber";
    string testStr2 = "Kabehsaner";

    Solution test;
    cout << test.checkInclusion(testStr2,testStr) << '\n';

    return 0;
}