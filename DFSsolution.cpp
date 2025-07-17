#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Node {
    int val;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val) {
        this->val = val;
    }

};

vector<int> DFS(Node* root) {
    if (root == nullptr) {
        return  { };
    }
    vector<int> vals;
    Node* curr = root;
    stack<Node*> Nodes;
    while (curr) {
        vals.push_back(curr->val);
        if (curr->left) {
            Nodes.push(curr->left);
        }
        if (curr->right) {
            Nodes.push(curr->right);
        }
        if (!Nodes.empty()) {
            curr = Nodes.top();
            Nodes.pop();
        }
        else {
            curr = nullptr;
        }
    }
    return vals;
}

vector<int> BFS(Node* root) {
    if (root == nullptr) {
        return { };
    }
    vector<int> vals;
    queue<Node*> Nodes;
    Node* curr = root;
    while (curr) {
        vals.push_back(curr->val);

        if (curr->left) {
            Nodes.push(curr->left);
        }
        if (curr->right) {
            Nodes.push(curr->right);
        }
        if (!Nodes.empty()) {
            curr = Nodes.front();
            Nodes.pop();
        }
        else {
            curr = nullptr;
        }
    }
    return vals;
}

bool DFSTargetRecursive(Node* root, int target) {
    if (root == nullptr) {
        return false;
    }
    if (target == root->val) {
        return true;
    }

    return DFSTargetRecursive(root->left,target) ||
        DFSTargetRecursive(root->right,target);


}

int treeSumDFS(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->val + treeSumDFS(root->left) + treeSumDFS(root->right);

}

int treeSumBFS(Node* root) {
    if (root == nullptr) return 0;
    int sum = 0;
    queue<Node*> Nodes;
    Nodes.push(root);
    Node* curr;
    while (Nodes.front()) {
        curr = Nodes.front();
        Nodes.pop();
        sum += curr->val;
        if (curr->left) Nodes.push(curr->left);
        if (curr->right) Nodes.push(curr->right);
    }
    return sum;


}


int treeMinRecursive(Node* root) {
    if (root == nullptr) {
        return numeric_limits<int>::max();
    }
    int leftMin = treeMinRecursive(root->left);
    int rightMin = treeMinRecursive(root->right);
    return min(root->val,min(leftMin,rightMin));
}

int maxPathSumRecursive(Node* root) {
    if (root == nullptr) {
        return numeric_limits<int>::min();
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->val;
    }
    const int leftMax = maxPathSumRecursive(root->left);
    const int rightMax = maxPathSumRecursive(root->right);

    return root->val + (leftMax > rightMax ? leftMax : rightMax);

}



int main() {
    Node* root = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    root->left = b;
    root->right = c;
    b->left = d;
    b->right = e;
    c->left = f;

    bool val = DFSTargetRecursive(root,10);
    cout << maxPathSumRecursive(root) << endl;

    return 0;
}