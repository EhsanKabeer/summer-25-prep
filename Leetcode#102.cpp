#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> Nodes;
        TreeNode* curr;
        Nodes.push(root);
        int nodesToAddOnLevel = 0;
        int nodesToAddOnNext = 1;
        bool createNewLevel = true;
        vector<int> currLevel;
        vector<vector<int>> vals;
        while (!Nodes.empty()) {
            curr = Nodes.front();
            Nodes.pop();
            if (createNewLevel) {
                if (!currLevel.empty()) {
                    vals.push_back(currLevel);
                }
                currLevel.clear();
                nodesToAddOnLevel = nodesToAddOnNext;
                nodesToAddOnNext = 0;
                createNewLevel = false;
            }
            currLevel.push_back(curr->val);
            nodesToAddOnLevel--;
            if (nodesToAddOnLevel == 0) {
                createNewLevel = true;
            }
            if (curr->left) {
                Nodes.push(curr->left);
                nodesToAddOnNext++;
            }
            if (curr->right) {
                Nodes.push(curr->right);
                nodesToAddOnNext++;
            }
        }
        if (!currLevel.empty()) {
            vals.push_back(currLevel);
        }
        return vals;

    }
};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right =  new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution test;
    vector<vector<int>> soln  = test.levelOrder(root);


    return 0;
}