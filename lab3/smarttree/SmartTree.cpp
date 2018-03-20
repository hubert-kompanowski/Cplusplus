//
// Created by hubert on 16.03.18.
//

#include "SmartTree.h"


namespace datastructures {



    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        auto new_leaf = std::make_unique<SmartTree>();
        new_leaf->left = nullptr;
        new_leaf->right = nullptr;
        new_leaf->value = value;
        return new_leaf;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        tree->left = std::move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        tree->right = std::move(right_subtree);
        return tree;
    }


    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if(unique_ptr){
            PrintTreeInOrder(unique_ptr->left, out);
            *out << unique_ptr->value;
            *out << ", ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }


    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string result;
        if(tree){
            result += '[' + std::to_string(tree->value) + ' ' + DumpTree(tree->left)
                      + ' ' + DumpTree(tree->right) + ']';
            return result;
        }
        return "[none]";
    }

    void tree_iter(const std::string &tree, int number_of_right_childs, std::string &in_tree, int &i,
               int &number_of_left_childs);

    std::unique_ptr<SmartTree> get_leaf_ptr(const std::string &in_tree);

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        if(tree == "[none]"){
            return nullptr;
        }

        std::string in_tree;
        int i = 1;
        for(i; i<=tree.size(); i++){
            if(tree.at(i) == ' '){
                break;
            }else{
                in_tree += tree.at(i);
            }
        }

        std::unique_ptr<SmartTree> leaf = get_leaf_ptr(in_tree);

        int number_of_left_childs = 0;
        int number_of_right_childs = 0;
        in_tree.clear();

        i++;
        tree_iter(tree, number_of_right_childs, in_tree, i, number_of_left_childs);


        if(!number_of_left_childs){
            leaf->left = nullptr;
        }else{
            leaf->left = RestoreTree(in_tree);
        }

        in_tree.clear();
        number_of_left_childs = 0;
        number_of_right_childs = 0;

        i+=2;
        tree_iter(tree, number_of_right_childs, in_tree, i, number_of_left_childs);

        if(!number_of_left_childs){
            leaf->right = nullptr;
        }else{
            leaf->right = RestoreTree(in_tree);
        }
        return leaf;
    }

    std::unique_ptr<SmartTree> get_leaf_ptr(const std::string &in_tree) {
        std::stringstream stream1;
        int int_number;
        stream1.str(in_tree);
        stream1 >> int_number;
        std::unique_ptr<SmartTree> leaf = CreateLeaf(int_number);
        return leaf;
    }


    void tree_iter(const std::string &tree, int number_of_right_childs,
                   std::string &in_tree, int &i, int &number_of_left_childs) {

        for(i; i <= tree.size(); i++){
             in_tree += tree.at(i);
             if(tree.at(i) == '['){
                 number_of_left_childs++;
             }
             if(tree.at(i) == ']'){
                 number_of_right_childs++;
             }
             if(number_of_left_childs == number_of_right_childs){
                 break;
             }
        }
    }
}