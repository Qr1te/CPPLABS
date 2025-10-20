#ifndef LAB8_ITERATOR_H
#define LAB8_ITERATOR_H

#include "Tree.h"
#include <stack>

template <typename T>
class Iterator {
private:
    std::stack<TreeNode<T>*> stk;
    TreeNode<T>* current;

    void pushLeft(TreeNode<T>* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

public:
    explicit Iterator(TreeNode<T>* root, bool isEnd = false) {
        if (isEnd) {
            current = nullptr;
        } else {
            current = nullptr;
            pushLeft(root);
            if (!stk.empty()) {
                current = stk.top();
                stk.pop();
                pushLeft(current->right);
            }
        }
    }

    T& operator*() { return current->data; }

    Iterator& operator++() {
        if (!stk.empty()) {
            current = stk.top();
            stk.pop();
            pushLeft(current->right);
        } else {
            current = nullptr;
        }
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
};

template <typename T>
Iterator<T> Tree<T>::begin() {
    return Iterator<T>(root);
}

template <typename T>
Iterator<T> Tree<T>::end() {
    return Iterator<T>(nullptr, true);
}


#endif//LAB8_ITERATOR_H
