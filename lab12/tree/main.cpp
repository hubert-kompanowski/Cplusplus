//
// Created by hubert on 25.05.18.
//

#include <iostream>
#include "Tree.h"

using namespace tree;

int main(){
    Tree<int> tree {5};
    tree.Insert(6);

    auto value = tree.Value();
    std::cout << value;
    std::cout << tree.Size();
    std::cout << tree.Depth();
}



/*
 *
 *
#include <memory>
#include <cmath>

namespace tree {

    template<class T>
    struct Node {
        T value;
        Node *left;
        Node *right;

        Node(T v) {
            this->value = v;
            this->left = nullptr;
            this->right = nullptr;
        }
        Node(T val, Node<T> *left, Node<T> *right) {
            this->value = val;
            this->left = left;
            this->right = right;
        }
        ~Node(){
            delete left;
            delete right;
        }
    };

    template<class T>
    class Tree {
    public:
        ~Tree(){
            delete root;
        }
        Tree(T v){
            root = new Node<T>(v);
            size = 1;
            depth = 1;
        }
        Tree(){
            root = nullptr;
            size = 0;
            depth = 0;
        }

        void TreeDelete(T r){
            if(r != nullptr){
                TreeDelete(r->left);

                TreeDelete(r->right);
            }
        }


        void addHelper(Node<T> *root, T val) {
            if (root->value > val) {
                if (!root->left) {
                    root->left = new Node<T>(val);
                } else {
                    addHelper(root->left, val);
                }
            } else {
                if (!root->right) {
                    root->right = new Node<T>(val);
                } else {
                    addHelper(root->right, val);
                }
            }
        }

        void Insert(const T &e) {
            size++;
            if (root) {
                this->addHelper(root, e);
            } else {
                root = new Node<T>(e);
            }
            depth =(size_t)(1+ log10(size)/log10(2));
        }

        T Value(){
            return root->value;
        }

        size_t Size(){
            return size;
        }
        size_t Depth(){
            return depth;
        }

    private:
        Node<T>* root;
        size_t size;
        size_t depth;

    };

}
 *
 */