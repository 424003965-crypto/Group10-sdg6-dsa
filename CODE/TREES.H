#ifndef TREES_H
#define TREES_H

#include "WaterTest.h"
#include <iostream>
using namespace std;

struct TreeNode {
    WaterTest data;
    TreeNode* left;
    TreeNode* right;
};

class BST {
private:
    TreeNode* root;
    void insert(TreeNode*& node, const WaterTest& t);
    void inorder(TreeNode* node);

public:
    BST();
    ~BST();
    void insert(const WaterTest& t);
    void display();
};

#endif
