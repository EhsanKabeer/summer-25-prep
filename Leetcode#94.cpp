#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> val;
        vector<int> leftVals = inorderTraversal(root->left);
        val.insert(val.end(),leftVals.begin(),leftVals.end());
        val.push_back(root->val);
        vector<int> rightVals = inorderTraversal(root->right);
        val.insert(val.end(),rightVals.begin(),rightVals.end());

        return val;


    }
};