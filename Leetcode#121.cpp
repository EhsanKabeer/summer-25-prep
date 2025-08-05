#include  <vector>
#include <iostream>
#include  <limits>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int currProfit = 0;
        for (int i = 1;i < prices.size();i++) {
            if (prices[i] < currMin) {
                currMin = prices[i];
            }
            else if (prices[i] - currMin > currProfit) {
                currProfit = prices[i] - currMin;
            }
        }
        return currProfit;

    }
};


int main() {
    Solution test;
    vector<int> testVec = {2,1,2,1,0,1,2};
    cout << test.maxProfit(testVec) << endl;
    return 0;
}