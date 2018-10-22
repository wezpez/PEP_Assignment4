#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

template <class T>
class TreeNode {

public:
    T data;
    unique_ptr<TreeNode> leftChild;
    unique_ptr<TreeNode> rightChild;
    TreeNode<T> * parent;

    TreeNode<T>(const T& d):data(d), parent(nullptr) {}

    void setLeftChild(TreeNode* child) {
        this->leftChild.reset(child);
        child->parent = this;
    }

    void setRightChild(TreeNode* child) {
        this->rightChild.reset(child);
        child->parent = this;
    }

    void write(ostream & o) const {
        if (leftChild){leftChild->write(o);}
        o << " " << data << " ";
        if (rightChild){rightChild->write(o);}
    }

};

// do not edit below this line

#endif
