#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        size_t lastIdx = digits.size() - 1;
        if(digits[lastIdx] == 9){
            while (digits[lastIdx] == 9) {
                if (lastIdx == 0) {
                    digits[lastIdx] = 1;
                    digits.push_back(0);
                    return digits;
                }
                else if (digits[lastIdx - 1] == 9) {
                    digits[lastIdx] = 0;
                    lastIdx--;
                }
                else if (digits[lastIdx -1] != 9) {
                    digits[lastIdx] = 0;
                    digits[lastIdx - 1] += 1;
                    return digits;
                }
            }
        }
        else{
            digits[lastIdx] += 1;
        }
        return digits;
    }
};

int main() {
    vector<int> test;
    test.push_back(9);
    test.push_back(9);
    test.push_back(3);

    Solution testing;

    test = testing.plusOne(test);
    for (auto& i : test) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}