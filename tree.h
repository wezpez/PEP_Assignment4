#ifndef TREE_H
#define TREE_H

#include "treenode.h"

template <class T>
class BinarySearchTree {

private:

    unique_ptr<TreeNode<T>> root;

public:

    //Default constructor
    BinarySearchTree(){};

    //copy constructor
    BinarySearchTree(const BinarySearchTree &original) {
        if (!original.root){
            return;
        }
        else {
            insert(original.root -> data);
            cloneTree(original.root.get());
        }
    }

    //Assignment operator
    BinarySearchTree& operator =(const BinarySearchTree &original){
        if (!original.root){
            return *this;
        }
        else {
            root.reset(nullptr);
            insert(original.root -> data);
            cloneTree(original.root.get());
            return *this;
        }

    }


    void cloneTree(TreeNode<T> * oldTreePos){
        if (oldTreePos->rightChild){
            insert(oldTreePos -> rightChild -> data);
            cloneTree(oldTreePos->rightChild.get());
        }

        if (oldTreePos->leftChild){
            insert(oldTreePos -> leftChild -> data);
            cloneTree(oldTreePos->leftChild.get());
        }
    }


    void write(ostream & o) const {
        if (root) {root->write(o);}
    }



    TreeNode<T>* insert(T newNode) {

        auto* nNode = new TreeNode<T>(newNode);
        TreeNode<T>* parent = nullptr;

        if(!root){
            root.reset(nNode);
        }
        else {

            TreeNode<T>* current;
            current = root.get();

            while(current)
            {
                parent = current;
                if (current->data < nNode->data)
                    current = current->rightChild.get();
                else
                    current = current->leftChild.get();
            }

            if (parent->data < nNode->data){
                parent->setRightChild(nNode);
            }
            else {
                parent->setLeftChild(nNode);
            }

        }

        return nNode;

    }



    TreeNode<T>* find(T targetNode) {

        if (targetNode == root->data){
            return root.get();
        }
        else {
            TreeNode<T>* current;
            current = root.get();

            while(current)
            {
                if (current-> data == targetNode){
                    return current;
                }
                else if (current-> data < targetNode){
                    current = current->rightChild.get();
                }
                else {
                    current = current->leftChild.get();
                }
            }

            return nullptr;
        }


    }

    // finds and returns a pointer to the left most node in the tree
    TreeNodeIterator<T> begin() {

        if (root == nullptr) {
            TreeNodeIterator<T> newIterator = TreeNodeIterator<T>(nullptr);
            return newIterator;
        }
        else {
            TreeNodeIterator<T> newIterator = TreeNodeIterator<T>(root.get());

            while (newIterator.current->leftChild){
                newIterator.current = newIterator.current-> leftChild.get();
            }

            return newIterator;
        }
    }


    TreeNodeIterator<T> end() {
        TreeNodeIterator<T> newIterator = TreeNodeIterator<T>(nullptr);
        return newIterator;
    }

    int maxDepth(){
        int treeMaxDepth = root->maxDepth(root.get());
        return treeMaxDepth;
    }


};



// do not edit below this line

#endif
