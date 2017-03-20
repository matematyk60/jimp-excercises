//
// Created by janek on 19.03.17.
//

#include "SmartTree.h"
#include <ostream>
#include <string>
#include <memory>
#include <sstream>


namespace datastructures{

    std::unique_ptr <struct SmartTree> CreateLeaf(int value){
        unique_ptr<SmartTree> new_leaf = make_unique<SmartTree>();
        new_leaf->value = value;
        new_leaf->left = nullptr;
        new_leaf->right = nullptr;
        return new_leaf;
    }

    std::unique_ptr <struct SmartTree> InsertLeftChild(std::unique_ptr<struct SmartTree> tree,
                                                       std::unique_ptr<struct SmartTree> left_subtree){
        if(tree!= nullptr) {
            tree->left = move(left_subtree);
            tree->left->left = nullptr;
            tree->left->right = nullptr;
        }
        return tree;

    }

    std::unique_ptr <struct SmartTree> InsertRightChild(std::unique_ptr<struct SmartTree> tree,
                                                        std::unique_ptr<struct SmartTree> right_subtree){
        if(tree!= nullptr) {
            tree->right = move(right_subtree);
            tree->right->left = nullptr;
            tree->right->right = nullptr;
        }
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<struct SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr){
            PrintTreeInOrder(unique_ptr->left, out);
            *out << unique_ptr->value << ", ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }



    void PrintTreeInOrderToString(const std::unique_ptr<struct SmartTree> &branch, std::string *ss, bool tf){
        if(branch){
            if(tf){
                *ss = "[";
                tf = false;
            }
            else
                *ss += " [";
            *ss += std::to_string(branch->value);
            PrintTreeInOrderToString(branch->left, ss, tf);
            PrintTreeInOrderToString(branch->right, ss, tf);
            *ss += "]";
        }
        else *ss += " [none]";
    }

    std::string DumpTree(const std::unique_ptr<struct SmartTree> &tree){
        std::string ss="";
        bool tf = true;
        PrintTreeInOrderToString(tree, &ss, tf);
        return ss;
    }


    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){

    }

}