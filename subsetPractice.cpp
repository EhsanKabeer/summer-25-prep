#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

class Subset {
public:
    //Processed will always be passed in a empty string initially
    vector<string> subseq(string processed, string unprocessed) {
        //base case
        if (unprocessed.empty()) {
            vector<string> result = {};
            result.push_back(processed);
            return result;
        }

        char ch = unprocessed[0];

        auto left = subseq(processed + ch,unprocessed.substr(1));
        auto right = subseq(processed,unprocessed.substr(1));

        left.insert(left.end(),right.begin(),right.end());
        return left;

    }

    vector<vector<int>> subset(vector<int> list) {
        vector<vector<int>> outer = {{}};

        for (int num : list) {
            int n = outer.size();
            for (int i = 0; i < n; i++) {
                vector<int> inner = outer[i];
                inner.push_back(num);
                outer.push_back(inner);
            }
        }

        return outer;
    }




    vector<vector<int>> subsetDups(vector<int> list) {
        sort(list.begin(),list.end());

        vector<vector<int>> outer = {{}};

        int prevNum = numeric_limits<int>::max();
        int prevN;
        for (int num : list) {
            int i = 0;
            int n = outer.size();
            if (num == prevNum) {
                i = prevN;
            }
            for (; i < n;i++) {
                vector<int> inner = outer[i];
                inner.push_back(num);
                outer.push_back(inner);
            }
            prevN = n;
            prevNum = num;

        }

        return outer;
    }

    void permutationPrint(string unprocessed, string processed) {

        if (unprocessed.empty()) {
            cout << processed << endl;
            return;
        }
        char ch = unprocessed[0];
        for (int i = 0;i <= processed.size();i++) {
            string start = processed.substr(0,i);
            string end = processed.substr(i,processed.size());
            permutationPrint(unprocessed.substr(1), start + ch + end);
        }
    }

    vector<string> permutationArray(string p, string up) {
        if (up.empty()) {
            vector<string> vec;
            vec.push_back(p);
            return vec;
        }

        char ch = up[0];
        vector<string> allPerms = {};
        for (int i = 0; i <= p.size();i++) {
            auto start = p.substr(0,i);
            auto end = p.substr(i,p.size());
            vector<string> temp = permutationArray(start + ch + end, up.substr(1));
            allPerms.insert(allPerms.end(),temp.begin(),temp.end());
        }

        return allPerms;


    }
};


int main() {
    Subset test;
    vector<string> testVec = {};
    vector<int> testArr = {2,1,2};
    //testVec = test.subsetDups(testArr);

    testVec = test.permutationArray("","abc");


    string a = std::to_string(static_cast<int>('b'));

    return 0;
}
