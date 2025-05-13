#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        vector<int> stairs;
        stairs.resize(n);
        stairs[0] = 1;
        stairs[1] = 2;
        for (int i = 2; i < n;i++) {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }
        return stairs[n - 1];
    }
};


int main() {
    Solution test;
    cout << test.climbStairs(3);

    return 0;
}