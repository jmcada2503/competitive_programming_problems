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

template <typename T>
class BinaryTreeNode {
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

struct ans {
    BinaryTreeNode<int>* node;
    unordered_map<int,bool> children;
};

ans f(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    if (root == nullptr) {
        unordered_map<int,bool> children;
        children[node1] = false;
        children[node2] = false;
        children[node3] = false;
        return {nullptr, children};
    }
    ans lans = f(root->left, node1, node2, node3);
    if (lans.node != nullptr) {
        return {lans.node, lans.children};
    }
    ans rans = f(root->right, node1, node2, node3);
    if (rans.node != nullptr) {
        return {rans.node, rans.children};
    }

    unordered_map<int,bool> children;
    children[node1] = lans.children[node1] || rans.children[node1];
    children[node2] = lans.children[node2] || rans.children[node2];
    children[node3] = lans.children[node3] || rans.children[node3];

    if (root->data == node1 || root->data == node2 || root->data == node3) {
        children[root->data] = true;
    }

    if (children[node1] && children[node2] && children[node3]) {
        return {root, children};
    }
    return {nullptr, children};
}

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    return f(root, node1, node2, node3).node;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);
    root->left->left->left = new BinaryTreeNode<int>(8);
    root->left->left->right = new BinaryTreeNode<int>(9);
    root->left->left->left->left = new BinaryTreeNode<int>(10);
    root->left->left->right->left = new BinaryTreeNode<int>(11);

    cout << lcaOfThreeNodes(root, 8, 9, 11)->data << endl;

    return 0;
}
