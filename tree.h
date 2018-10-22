#ifndef TREE_H
#define TREE_H

#include "treenode.h"

template <class T>
class BinarySearchTree {

private:

    unique_ptr<TreeNode<T>> root;

public:

    BinarySearchTree(){};



    void write(ostream & o) const {
        root->write(o);
    }



    TreeNode<T>* insert(T newNode) {

        TreeNode<T>* nNode = new TreeNode<T>(newNode);
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
                parent->rightChild.reset(nNode);
            }
            else {
                parent->leftChild.reset(nNode);
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




};



// do not edit below this line

#endif
