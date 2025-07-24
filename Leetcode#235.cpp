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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* currLowest = root;
        TreeNode* currForP = root;
        TreeNode* currForQ = root;
        while (currForP != p && currForQ != q) {
            if (currForP->val > p->val) {
                currForP = currForP->left;
            }
            else if (currForP->val < p->val) {
                currForP = currForP->right;
            }

            if (currForQ->val > q->val) {
                currForQ = currForQ->left;
            }
            else if (currForQ->val < q->val) {
                currForQ = currForQ->right;
            }

            if (currForP == currForQ) {
                currLowest = currForP;
            }


        }
        return currLowest;
    }
};


int main() {
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n9 = new TreeNode(9);

    // next level
    TreeNode* n4 = new TreeNode(4, n3, n5);
    TreeNode* n2 = new TreeNode(2, n0, n4);
    TreeNode* n8 = new TreeNode(8, n7, n9);

    // root
    TreeNode* root = new TreeNode(6, n2, n8);
    Solution test;
    TreeNode* soln = test.lowestCommonAncestor(root,n4,n7);


    return 0;
}