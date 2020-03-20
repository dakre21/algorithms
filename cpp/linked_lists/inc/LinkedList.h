#pragma once

#include <iostream>

template<typename T>
class LinkedList;

template<typename T>
class Node 
{
public:
    Node() {
        next_ = nullptr;
    }

    Node(const T& data) : data_(data) {
        // Do nothing
    }

    Node(const Node& node) {
        data_ = node.getData();
    }

    Node(Node&&) = delete;
    Node& operator=(Node&&) = delete;

    T getData() const {
        return data_;
    }

    Node* getNext() const {
        return next_;
    }

protected:
    friend LinkedList<T>;

    Node* next_;

private:
    T data_;
};


template<typename T>
class LinkedList
{
public:
    LinkedList() {
        head_ = &root_;
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    LinkedList(LinkedList&&) = delete;
    LinkedList& operator=(LinkedList&&) = delete;

    void printList() {
        Node<T>* node = root_.getNext();
        while (node != nullptr) {
            std::cout << node->getData() << std::endl;
            node = node->getNext();
        }
    }

    void addNode(Node<T>& node) {
        head_->next_ = &node;
        head_ = &node;
        node.next_ = nullptr;
    }

    Node<T>* getFirst() {
        return root_.getNext();
    }

private:
    Node<T> root_;
    Node<T>* head_;
};
