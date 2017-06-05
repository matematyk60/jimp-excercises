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
        Node(T value, Node<T> *parent = nullptr);

        void SetRight(T value, Node<T> *parent);

        void SetLeft(T value, Node<T> *parent);

        void SetParent(Node<T> *parent);

        Node<T> *GetLeft();

        Node<T> *GetRight();

        size_t SubTreeSize();

        T GetValue();

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
        bool found = false;
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
    Node<T> *Node<T>::GetRight() {
        if (right_ != nullptr) {
            return right_.get();
        } else {
            return nullptr;
        }
    }

    template<class T>
    void Node<T>::SetParent(Node<T> *parent) {
        parent_ = parent;
    }

    template<class T>
    T Node<T>::GetValue() {
        return value_;
    }

    template<class T>
    void Node<T>::SetRight(T value, Node<T> *parent) {
        right_ = std::make_unique<Node<T>>(value, parent);
    }

    template<class T>
    void Node<T>::SetLeft(T value, Node<T> *parent) {
        left_ = std::make_unique<Node<T>>(value, parent);
    }

    template<class T>
    Node<T>::Node(T value, Node<T> *parent) {
        left_ = nullptr;
        right_ = nullptr;
        value_ = value;
        parent_ = parent;
    }

    template<class T>
    class Tree {
    public:
        Tree(T value = T{});

        void Insert(T value);

        T Value() const;

        void Inserting(T value, Node<T> *node);

        size_t Size() const;

        size_t Depth() const;

        bool Find(T value) const;

    private:
        std::unique_ptr<Node<T>> root_;
    };

    template<class T>
    Tree<T>::Tree(T value) {
        root_ = std::make_unique<Node<T>>(value);
    }

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

    template<class T>
    bool Tree<T>::Find(T value) const {
        return root_->Find(value);
    }

    template<class T>
    T Tree<T>::Value() const {
        return (*root_).GetValue();
    }

    template<class T>
    size_t Tree<T>::Size() const {
        return root_->SubTreeSize();
    }

    template<class T>
    size_t Tree<T>::Depth() const {
        return root_->MaxSubTree();
    }
}


#endif //JIMP_EXERCISES_TREE_H