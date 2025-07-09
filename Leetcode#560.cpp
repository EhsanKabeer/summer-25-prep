#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool currArrSum(int* start, int* end,int k) {
        int currSum = *start;
        while (start != end) {
            currSum += *end;
            end--;
        }
        return k == currSum;
    }
public:
    int subarraySum(vector<int>& nums, int k) {

        int totalSubArr = 0;
        int* begin = &nums[0];
        int* end = &nums[nums.size() - 1];
        for (int i = 0;i < nums.size();i++) {
            for (int j = i;j < nums.size();j++) {
                if (currArrSum(begin,end,k)) totalSubArr++;
                if (begin != end) {
                    end--;
                }
            }
            begin++;
            end = &nums[nums.size() - 1];
        }
        return totalSubArr;
    }
};


int main() {
    Solution attempt;

    vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);


    cout << attempt.subarraySum(test,2);

    return 0;
}
