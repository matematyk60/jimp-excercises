//
// Created by matematyk60 on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H


#include <memory>

namespace tree {
    template<class T>
    class Node {
    public:
        Node(T value, Node<T> *parent = nullptr) {
            left_ = nullptr;
            right_ = nullptr;
            value_ = value;
            parent_ = parent;
        }

        void SetRight(T value, Node<T> *parent) { right_ = std::make_unique<Node<T>>(value, parent); }

        void SetLeft(T value, Node<T> *parent) { left_ = std::make_unique<Node<T>>(value, parent); }

        void SetParent(Node<T> *parent) { parent_ = parent; }

        Node<T> *GetLeft();

        Node<T> *GetRight();

        T GetValue() { return value_; }

        size_t SubTreeSize();

        size_t MaxSubTree();

        bool Find(T value);

    private:
        std::unique_ptr<Node<T>> left_;
        T value_;
        std::unique_ptr<Node<T>> right_;
        Node<T> *parent_;
    };


    template<class T>
    Node<T> *Node<T>::GetLeft() {
        if (left_ != nullptr) {
            return left_.get();
        } else {
            return nullptr;
        }
    }

    template<class T>
    Node<T> *Node<T>::GetRight() {
        if (right_ != nullptr) {
            return right_.get();
        } else {
            return nullptr;
        }
    }

    template<class T>
    size_t Node<T>::SubTreeSize() {
        size_t size = 0;
        if (this->GetLeft() != nullptr) {
            size += this->GetLeft()->SubTreeSize();
        }
        size += 1;
        if (this->GetRight() != nullptr) {
            size += this->GetRight()->SubTreeSize();
        }
        return size;
    }

    template<class T>
    size_t Node<T>::MaxSubTree() {
        size_t left;
        size_t right;
        if (this->GetLeft() == nullptr) {
            left = 0;
        } else {
            left = this->GetLeft()->MaxSubTree();
        }
        if (this->GetRight() == nullptr) {
            right = 0;
        } else {
            right = this->GetRight()->MaxSubTree();
        }
        return std::max(left, right) + 1;
    }

    template<class T>
    bool Node<T>::Find(T value) {
        bool found;
        if (value_ == value) {
            return true;
        }
        if (value < value_) {
            if (this->GetLeft() == nullptr) {
                return false;
            }
            found = this->GetLeft()->Find(value);
        } else {
            if (this->GetRight() == nullptr) {
                return false;
            }
            found = this->GetRight()->Find(value);
        }
        return found;
    }


    template<class T>
    class Tree {
    public:
        Tree(T value = T{}) { root_ = std::make_unique<Node<T>>(value); }

        void Insert(T value);

        T Value() const { return (*root_).GetValue(); }

        void Inserting(T value, Node<T> *node);

        size_t Size() const { return root_->SubTreeSize(); }

        size_t Depth() const { return root_->MaxSubTree(); }

        bool Find(T value) const { return root_->Find(value); }

    private:
        std::unique_ptr<Node<T>> root_;
    };


    template<class T>
    void Tree<T>::Insert(T value) {
        Inserting(value, root_.get());
    }

    template<class T>
    void Tree<T>::Inserting(T value, Node<T> *node) {
        if (value <= node->GetValue()) {
            if (node->GetLeft() == nullptr) {
                node->SetLeft(value, node);
                return;
            } else {
                Inserting(value, node->GetLeft());
            }
        } else {
            if (node->GetRight() == nullptr) {
                node->SetRight(value, node);
                return;
            } else {
                Inserting(value, node->GetRight());
            }
        }
    }
}


#endif //JIMP_EXERCISES_TREE_H