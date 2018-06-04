//
// Created by hubert on 25.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <vector>
#include <memory>

namespace tree {

    template<class T>
    class Tree {
    public:
        Tree(){
            size = 0;
        }

        Tree(const T &e) {
            my_set(e);

        }

        void Insert(const T &e) {
            if (size == 0) {
                my_set(e);
            } else {
                size_t i = 2;
                std::unique_ptr<Tree<T>>* next;
                if (e < node)
                    next = &Left;
                else
                    next = &Right;
                std::unique_ptr<Tree<T>>* temp = next;
                while (*next) {
                    if (e < next->operator->()->Value()) {
                        temp = next;
                        next = &next->operator->()->Left;
                    }
                    else {
                        temp = next;
                        next = &next->operator->()->Right;
                    }
                    i++;
                }
                if( i > depth)
                    depth= i;
                *next = std::make_unique<Tree<T>>(e);
                next->operator->()->parent = temp;
                next->operator->()->root = root;
                next->operator->()->level = i;
            }
            size++;
        }

        void my_set(const T &e) {
            node = e;
            size = 1;
            depth = 1;
            Left = nullptr;
            Right = nullptr;
            root = this;
            parent = nullptr;
            level =1;
        }

        bool Find(const T &elem){
            std::unique_ptr<Tree> *next= this;
            while( *next != nullptr && next->operator->()->Value() != elem) {
                if (elem < next->operator->()->Value())
                    next = &next->operator->()->Left;
                else
                    next = &next->operator->()->Right;
            }
            if(next == nullptr)
                return false;
            return true;

        }

        size_t Depth(){
            return depth;
        }

        size_t Size(){
            return size;
        }

        T Value(){
            return node;
        }

        Tree<T>* LeftObj(){
            return &*Left;
        }

        Tree<T>* RightObj(){
            return &*Right;
        }

        Tree<T>* Parent(){
            if(level==1)
                return nullptr;
            if(level==2)
                return root;
            return &**parent;
        }

        Tree<T>* Root(){
            return root;
        }



    private:
        T node;
        Tree<T>* root;
        std::unique_ptr<Tree<T>>* parent;
        std::unique_ptr<Tree<T>> Left;
        std::unique_ptr<Tree<T>> Right;
        size_t size;
        size_t depth;
        size_t level;
    };
}

#endif //JIMP_EXERCISES_TREE_H






