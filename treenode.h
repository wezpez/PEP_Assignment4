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
        if (leftChild){leftChild-> write(o);}
        o << " " << data << " ";
        if (rightChild){rightChild-> write(o);}
    }

    int maxDepth(TreeNode* currentNode){

        if (currentNode == nullptr){
            return 0;
        }
        else {
            int leftDepth = maxDepth(currentNode -> leftChild.get());
            int rightDepth = maxDepth(currentNode -> rightChild.get());

            if (rightDepth > leftDepth){
                return rightDepth + 1;
            }
            else {
                return leftDepth + 1;
            }
        }
    }


};

template <class T>
class TreeNodeIterator {

public:

    TreeNode<T> * current;


    TreeNodeIterator(TreeNode<T> * currentIn)
    : current(currentIn) {}


    T & operator*() {
        return current -> data;
    }

    bool operator==(const TreeNodeIterator & rhs) {
        return (current == rhs.current);
    }

    bool operator!=(const TreeNodeIterator & rhs) {
        return (current != rhs.current);
    }


    void operator++() {
        if(current->rightChild) {
            current = current -> rightChild.get();
            while (current->leftChild){
                current = current -> leftChild.get();
            }
        }
        else if(current->parent){
            while(current->parent){
                if(current->parent->data > current->data) {
                    break;
                }
                current = current->parent;
            }
            current = current->parent;
        }
        else {
            current = nullptr;
        }

    }

};

// do not edit below this line

#endif
