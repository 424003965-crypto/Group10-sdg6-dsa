#include "Trees.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    function<void(TreeNode*)> destroy = [&](TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    };
    destroy(root);
}

void BST::insert(TreeNode*& node, const WaterTest& t) {
    if (!node) { node = new TreeNode{t, nullptr, nullptr}; return; }
    if (t.pH < node->data.pH) insert(node->left, t);
    else insert(node->right, t);
}

void BST::insert(const WaterTest& t) { insert(root, t); }

void BST::inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << "ID: " << node->data.id
         << " | pH: " << node->data.pH
         << " | Color: " << node->data.colorCode
         << " | Status: " << node->data.status << "\n";
    inorder(node->right);
}

void BST::display() {
    if (!root) { cout << "BST is empty.\n"; return; }
    cout << "Tests sorted by pH (inorder traversal):\n";
    inorder(root);
}
