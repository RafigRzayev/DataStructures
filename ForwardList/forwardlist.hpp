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
        public:
            Iterator(Node* node = nullptr) : node_{node} {}
            Iterator& operator++() { node_ = node_->next_; return *this; }
            int& operator*() { return node_->val_; }
            bool operator==(const Iterator& r) const { return node_ == r.node_; }
            bool operator!=(const Iterator& r) const { return node_ != r.node_; }
        private:
            Node* node_;
            friend class ForwardList;
    };

    ForwardList() = default;
    ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);
    ForwardList(ForwardList&& other);
    ForwardList& operator=(ForwardList&& other);
    ~ForwardList();

    size_t size() const;
    bool empty() const;

    Iterator begin() const;
    Iterator end() const;
    int& front();
    int& back();

    void clear();
    void pushFront(int val);
    void popFront();
    void pushBack(int val);
    void popBack();
    void remove(int val);
    void eraseAfter(Iterator it);

    void print() const; 
    void printRec() const; 
    void printReverseRec() const;

    void reverse();
    void reverseRec();
    void reverseStack();
private:
    void printRec(Node* head) const;
    void printReverseRec(Node* head) const;
    void reverseRec(Node* head);
    Node* head_ = nullptr;
};