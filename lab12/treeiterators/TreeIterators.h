//
// Created by hubert on 04.06.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <memory>
#include <algorithm>
#include "Tree.h"

namespace tree {

    template<class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(Tree<T>* other){
            Node = other;
            while(Node->LeftObj()){
                Node = Node->LeftObj();
            }
        }

        T operator*() const{
            return Node->Value();
        }
        
        void operator++(){
            if(Node->RightObj()!= nullptr) {
                Node = Node->RightObj();
                while(Node->LeftObj()!= nullptr) {
                    Node = Node->LeftObj();
                }
            }
            else{
                if(Node == Node->Parent()->LeftObj())
                    Node= Node->Parent();
                else {
                    while (Node == Node->Parent()->RightObj()) {
                        Node = Node->Parent();
                    }
                    Node= Node->Parent();
                }
            }
        }
        
        bool operator!=(const InOrderTreeIterator &other) const{
            return Node != other.Node;
        }

    private:
        Tree<T>* Node;
    };
    
    
    template<class T>
    class InOrderTreeView{
    public:
        InOrderTreeView(Tree<T>* root){
            Root = root;
        }
        
        Tree<T>* ConstBegin() const{
            Tree<T>* temp = Root;
            while(temp->LeftObj()!= nullptr){
                temp = temp->LeftObj();
            }
            return temp;
        }
        
        Tree<T>* ConstEnd() const{
            Tree<T>* temp = Root;
            while(temp->RightObj()!= nullptr){
                temp = temp->RightObj();
            }
            return temp;
        }
        
        InOrderTreeIterator<T> cbegin() const{
            return InOrderTreeIterator<T>(ConstBegin());
        }
        
        InOrderTreeIterator<T> cend() const{
            return InOrderTreeIterator<T>(ConstEnd());
        }
        
        InOrderTreeIterator<T> begin() const{
            return InOrderTreeIterator<T>(cbegin());
        }
        
        InOrderTreeIterator<T> end() const{
            return InOrderTreeIterator<T>(cend());
        }

    private:
        Tree<T>* Root;
    };

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree){
        return InOrderTreeView<T>(tree);
    }



    template <class T>
    class PostOrderTreeIterator {
    public:
        PostOrderTreeIterator(){}
        PostOrderTreeIterator (Tree<T>* arg) : root_(arg) {
            InsertValues(root_);
            std::reverse(values_.begin(), values_.end());
        }

        void InsertValues(Tree<T> *tree) {
            if(tree->LeftObj()) InsertValues(tree->LeftObj());
            if(tree->RightObj()) InsertValues(tree->RightObj());
            values_.push_back(tree->Value());
        }

        T operator*() {
            return values_.back();
        }

        void operator++() {
            values_.pop_back();
        }

        bool operator!=(const PostOrderTreeIterator &it2) const {
            return values_!=it2.values_;
        }

    private:
        Tree<T>* root_;
        std::vector<T> values_;
    };

    template <class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView<T>( Tree<T>* tree) : tree_(tree){}

        PostOrderTreeIterator<T> begin() {
            return PostOrderTreeIterator<T>{tree_};
        }

        PostOrderTreeIterator<T> end() {
            return PostOrderTreeIterator<T>();
        }

    private:
        Tree<T>* tree_;
    };

    template <class T>
    PostOrderTreeView<T> PostOrder(Tree<T>* tree){
        return PostOrderTreeView<T>(tree);
    }




    template<class T>
    class PreOrderTreeIterator{
    public:
        PreOrderTreeIterator(Tree<T>* node){
            Node = node;
        }

        T operator*() const{
            return Node->Value();
        }

        void operator++(){
            if(Node->LeftObj()) {
                Node = Node->LeftObj();
            }
            else if(Node->RightObj())
                Node = Node->RightObj();
            else{
                if(Node == Node->Parent()->LeftObj()) {
                    while(!Node->RightObj())
                        Node=Node->Parent();
                    Node= Node->RightObj();
                }
                else {
                    while (Node == Node->Parent()->RightObj())
                        Node = Node->Parent();
                    Node=Node->Parent();
                    while(!Node->RightObj())
                        Node=Node->Parent();
                    Node= Node->RightObj();
                }
            }
        }
        bool operator!=(const PreOrderTreeIterator &other) const{
            return Node!=other.Node;
        }

    private:
        Tree<T>* Node;
    };

    template<class T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView(Tree<T>* root){
            Root = root;
        }

        Tree<T>* ConstBegin() const{
            return Root;
        }

        Tree<T>* ConstEnd() const{
            Tree<T>*temp = Root;
            while(temp->RightObj() || temp->LeftObj()){
                if(temp->RightObj())
                    temp = temp->RightObj();
                else
                    temp= temp->LeftObj();
            }
            return temp;
        }

        PreOrderTreeIterator<T> cbegin() const{
            return PreOrderTreeIterator<T>(ConstBegin());
        }

        PreOrderTreeIterator<T> cend() const{
            return PreOrderTreeIterator<T>(ConstEnd());
        }

        PreOrderTreeIterator<T> begin() const{
            return PreOrderTreeIterator<T>(cbegin());
        }

        PreOrderTreeIterator<T> end() const{
            return PreOrderTreeIterator<T>(cend());
        }

    private:
        Tree<T>* Root;
    };


    template <class T>
    PreOrderTreeView<T> PreOrder(Tree<T>* tree){
        return PreOrderTreeView<T>(tree);
    }
}

#endif //JIMP_EXERCISES_TREEITERATORS_H
