//
// Created by janek on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H


#include <memory>
#include <vector>
#include "../tree/Tree.h"

using ::std::vector;

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

        //private:
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

        Node<T> *Root() { return root_.get(); };

        void Insert(T value);

        T Value() const { return (*root_).GetValue(); }

        void Inserting(T value, Node<T> *node);

        size_t Size() const { return root_->SubTreeSize(); }

        size_t Depth() const { return root_->MaxSubTree(); }

        bool Find(T value) const { return root_->Find(value); }

        //private:
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


    template<class T>
    class TreeIterator {
    public:
        TreeIterator(Node<T> *head_) : head_(head_) {}

        virtual void CreateAnswer(Node<T> *answer) = 0;

        T operator++() { if (size_ >= 0) ++size_; }

        T operator*() { return answer_[size_]; }

        bool operator!=(const TreeIterator &second) const {
            return (answer_ != second.answer_ or size_ != second.size_);
        }

        void setIterator(const size_t &value) { size_ = value; }

        size_t size() const { return answer_.size(); }

        void pushBackValue(const T &val) { answer_.push_back(val); }

    private:
        Node<T> *head_;
        vector<T> answer_;
        size_t size_;
    };

    template<class T>
    class PreOrderTreeIterator : public TreeIterator<T> {
    public:
        PreOrderTreeIterator(Node<T> *head_) : TreeIterator<T>(head_) {
            CreateAnswer(head_);
            this->setIterator(0);
        }

        void CreateAnswer(Node<T> *answer) override {
            this->pushBackValue(answer->value_);
            if (answer->left_ != nullptr)
                CreateAnswer(answer->left_.get());
            if (answer->right_ != nullptr)
                CreateAnswer(answer->right_.get());
        }
    };

    template<class T>
    class InOrderTreeIterator : public TreeIterator<T> {
    public:
        InOrderTreeIterator(Node<T> *head_) : TreeIterator<T>(head_) {
            CreateAnswer(head_);
            this->setIterator(0);
        }

        void CreateAnswer(Node<T> *answer) override {
            if (answer->left_ != nullptr)
                CreateAnswer(answer->left_.get());
            this->pushBackValue(answer->value_);
            if (answer->right_ != nullptr)
                CreateAnswer(answer->right_.get());
        }
    };

    template<class T>
    class PostOrderTreeIterator : public TreeIterator<T> {
    public:
        PostOrderTreeIterator(Node<T> *head_) : TreeIterator<T>(head_) {
            CreateAnswer(head_);
            this->setIterator(0);
        }

        void CreateAnswer(Node<T> *answer) override {

            if (answer->left_ != nullptr)
                CreateAnswer(answer->left_.get());

            if (answer->right_ != nullptr)
                CreateAnswer(answer->right_.get());

            this->pushBackValue(answer->value_);
        }
    };


    template<class T>
    class PreOrderTreeView {
    public:
        PreOrderTreeView(Tree<T> *tree) : actualplace_(tree->Root()) {}

        PreOrderTreeIterator<T> begin() {
            actualplace_.setIterator(0);
            return actualplace_;
        }

        PreOrderTreeIterator<T> end() {
            actualplace_.setIterator(actualplace_.size() - 1);
            return actualplace_;
        }

    private:
        PreOrderTreeIterator<T> actualplace_;
    };

    template<class T>
    class InOrderTreeView {
    public:
        InOrderTreeView(Tree<T> *tree) : actualplace_(tree->Root()) {}

        InOrderTreeIterator<T> begin() {
            actualplace_.setIterator(0);
            return actualplace_;
        }

        InOrderTreeIterator<T> end() {
            actualplace_.setIterator(actualplace_.size() - 1);
            return actualplace_;
        }

    private:
        InOrderTreeIterator<T> actualplace_;
    };

    template<class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(Tree<T> *tree) : actualplace_(tree->Root()) {}

        PostOrderTreeIterator<T> begin() {
            actualplace_.setIterator(0);
            return actualplace_;
        }

        PostOrderTreeIterator<T> end() {
            actualplace_.setIterator(actualplace_.size() - 1);
            return actualplace_;
        }

    private:
        PostOrderTreeIterator<T> actualplace_;
    };


    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    };

    template<typename T>
    InOrderTreeView<T> InOrder(Tree<T> *tree) {
        return InOrderTreeView<T>(tree);
    };

    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    };
}

#endif //JIMP_EXERCISES_TREE_H