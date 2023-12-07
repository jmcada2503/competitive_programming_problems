#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

#define endl '\n'

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void clone(deque<Node*> &copy, deque<Node*> &original, set<Node*> &visited, map<int,Node*> nodes) {
        cout << "Faltantes: ";
        for (auto i=copy.begin(); i!=copy.end(); i++) cout << (*i)->val << ' '; cout << endl;

        visited.insert(original.front());

        if (copy.size()) {
            vector<Node*> neighbors;
            for (int i=0; i<original.front()->neighbors.size(); i++) {
                if (visited.find(original.front()->neighbors[i]) == visited.end()) {
                    Node* n = new Node(original.front()->neighbors[i]->val);
                    nodes[n->val] = n;
                    cout << "value neighbors[i]: " << original.front()->neighbors[i]->val << endl;
                    cout << "value n: " << n << endl;
                    neighbors.push_back(n);
                    original.push_back(original.front()->neighbors[i]);
                    copy.push_back(n);
                    visited.insert(original.front()->neighbors[i]);
                }
                else {
                    neighbors.push_back(nodes[(original.front()->neighbors[i]->val)]);
                }
            }
            copy.front()->neighbors = neighbors;
            copy.pop_front();
            original.pop_front();

            clone(copy, original, visited, nodes);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node != nullptr) {
            Node* n = new Node(node->val);

            deque<Node*> original, copy;
            original.push_back(node);
            copy.push_back(n);

            map<int,Node*> nodes;
            nodes[node->val] = n;

            set<Node*> visited;

            clone(copy, original, visited, nodes);

            return n;
        }
        return nullptr;
    }
};

int main() {
    Node a(1), b(2), c(3), d(4);
    a.neighbors.push_back(&b);
    a.neighbors.push_back(&d);
    b.neighbors.push_back(&a);
    b.neighbors.push_back(&c);
    c.neighbors.push_back(&b);
    c.neighbors.push_back(&d);
    d.neighbors.push_back(&a);
    d.neighbors.push_back(&c);

    Solution solution;
    Node* ans = solution.cloneGraph(&a);
    if (ans == &a) {
        cout << "Returning same graph :(" << endl;
    }
    else {
        cout << "Returning copy:" << endl;
        set<Node*> visited;
        deque<Node*> queue;
        queue.push_back(ans);
        visited.insert(ans);
        while (queue.size()) {
            cout << queue.front()->val << endl;
            for (auto i : queue.front()->neighbors) {
                if (visited.find(i) == visited.end()) {
                    queue.push_back(i);
                    visited.insert(i);
                }
            }
            queue.pop_front();
        }
    }

    return 0;
}
