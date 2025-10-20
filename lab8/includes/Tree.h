#ifndef LAB8_TREE_H
#define LAB8_TREE_H

#include <iostream>
#include "TreeNode.h"


template <typename T>
class Iterator;

template <typename T>
class Tree {
private:
    TreeNode<T>* root;
    void deleteNode(TreeNode<T>* node){
        if (node) {
            deleteNode(node->left);
            deleteNode(node->right);
            delete node;
        }
    }
public:
    Tree():root(nullptr){}
    ~Tree(){ deleteNode(root);}

    void insert(const T& value) {
        if (!root) {
            root = new TreeNode<T>(value);
            return;
        }
        TreeNode<T>* current = root;
        while (true) {
            if (value < current->data) {
                if (!current->left) {
                    current->left = new TreeNode<T>(value);
                    return;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = new TreeNode<T>(value);
                    return;
                }
                current = current->right;
            }
        }
    }
    TreeNode<T>* getRoot() const { return root; }

    Iterator<T> begin();
    Iterator<T> end();
};


#endif//LAB8_TREE_H
