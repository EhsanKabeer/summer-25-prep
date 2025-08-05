#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

using adjList = unordered_map<char,vector<char>>;

void DFS(unordered_map<char,vector<char>> g,char root) {
    stack<char> s;
    s.push(root);

    while (!s.empty()) {
        auto curr = s.top();
        s.pop();
        cout << curr << endl;
        for (auto node : g[curr]) {
            s.push(node);
        }
    }
}

void DFSRecursive(unordered_map<char,vector<char>> g,char root) {
    cout << root << endl;
    for (auto node : g[root]) {
        DFSRecursive(g,node);
    }
}


void BFS(unordered_map<char,vector<char>> g,char root) {
    queue<char> q;
    q.push(root);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        cout << curr << endl;
        for (auto node : g[curr]) {
            q.push(node);
        }
    }
}

bool explore(unordered_map<char,vector<char>> g,char curr,unordered_set<char>& visited) {
    if (visited.contains(curr)) {
        return false;
    }
    visited.insert(curr);
    for (auto node : g[curr]) {
        explore(g,node,visited);
    }
    return true;
}

int connectedComponents(unordered_map<char,vector<char>> g) {
    int count = 0;
    unordered_set<char> visited;
    for (const auto& key : g) {
        if (explore(g,key.first,visited)) {
            count++;
        }
    }
    return count;
}


int componentSize(unordered_map<char,vector<char>> g,char curr,unordered_set<char>& visited) {
    if (visited.contains(curr)) {
        return 0;
    }
    visited.insert(curr);
    int count = 1;
    for (auto node : g[curr]) {
        count += componentSize(g,node,visited);
    }
    return count;
}

int largestComponent(unordered_map<char,vector<char>> g) {
    int count = 0;
    unordered_set<char> visited;

    for (auto key : g) {
        count = max(count,componentSize(g,key.first,visited));
    }
    return count;
}


int shortestPath(unordered_map<char,vector<char>> g, char root,char target) {
    queue<pair<char,int>> nodes;
    unordered_set<char> visited;
    visited.insert(root);
    nodes.emplace(root,0);
    while (!nodes.empty()) {
        auto curr = nodes.front();
        nodes.pop();
        if (curr.first == target) {
            return curr.second;
        }

        for (auto node : g[curr.first]) {
            if (!visited.contains(curr.first)) {
                nodes.emplace(node,curr.second + 1);
                visited.insert(curr.first);
            }
        }
    }
    return -1;

}

unordered_map<char,vector<char>> edgeToAdjacency(vector<vector<char>> e) {
    unordered_map<char,vector<char>> g;
    for (auto edges : e) {
        if (!g.contains(edges[0])) g[edges[0]] = {};
        if (!g.contains(edges[1])) g[edges[1]] = {};

        g[edges[0]].push_back(edges[1]);
        g[edges[1]].push_back(edges[0]);
    }
    return g;

}




int main() {
    unordered_map<char,vector<char>> graph;
    graph['0'] = {'8','1','5'};
    graph['1'] = {'0'};
    graph['5'] = {'0','8'};
    graph['8'] = {'0','5'};
    graph['2'] = {'3','4'};
    graph['3'] = {'2','4'};
    graph['4'] = {'3','2'};
    vector<vector<char>> edgeList = {
      {'w','x'},
        {'x','y'},
        {'z','y'},
        {'z','v'},
        {'w','v'}
    };

    adjList test = edgeToAdjacency(edgeList);



    cout << shortestPath(test,'w','z');



    return 0;
}