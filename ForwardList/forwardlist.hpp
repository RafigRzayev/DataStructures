#pragma once
#include <cstddef>

class ForwardList {
private:
    struct Node {
        int val_;
        Node* next_;
        Node() : val_{}, next_{nullptr} {}
        Node(int val, Node* next = nullptr) : val_{val}, next_{next} {}
    };
public:
    class Iterator {

    };
public:
    size_t size() const;
    bool empty() const;
    void clear();
    void pushFront(int val);
    void pushBack(int val);
    void popBack();
    void popFront();
    void print() const; 
    void printRec() const; 
    void printReverseRec() const;
    void reverse();
    void reverseRec(Node* head);
private:
    void printRec(Node* head) const;
    void printReverseRec(Node* head) const;
    Node* head_ = nullptr;
};