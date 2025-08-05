#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        int left = 0;
        int right =  p.size() - 1;
        vector<int> idxs = {};
        vector<int> answerVec(26,0);
        vector<int> potentialVec(26,0);
        for (int i = 0; i<p.size();i++) {
            answerVec[p[i] - 'a']++;
            potentialVec[s[i] - 'a']++;
        }
        
        while (right < s.size()) {
            if (answerVec == potentialVec) {
                idxs.push_back(left);
            }
            potentialVec[s[left] - 'a']--;
            left++;
            right++;
            if (right == s.size()) break;
            potentialVec[s[right] - 'a']++;
        }

        return idxs;
    }
};


int main() {
    Solution test;
    test.findAnagrams("abab","ab");

    return 0;
}