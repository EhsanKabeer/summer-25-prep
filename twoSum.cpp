#include <iostream>
#include  <vector>
#include  <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, pair<bool,int>> targetFinder;
        for (int i = 0; i < nums.size(); i++) {
            targetFinder[nums[i]] = make_pair(true,i);
        }

        int remainder;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            remainder = target - nums[i];
            pair<bool,int> potential = targetFinder[remainder];
            if (potential.first == true && potential.second != i) {
                result.push_back(i);
                result.push_back(potential.second);
                return result;
            }
        }

    }
};

int main() {
    Solution testing;
    vector<int> testVec = {2,7,11,15};
    auto result = testing.twoSum(testVec,22);

}