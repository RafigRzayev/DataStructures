#pragma once
#include <cstddef>

class ForwardList {
private:
    // internal node implementation
    struct Node {
        int val_;
        Node* next_;
        Node() : val_{}, next_{nullptr} {}
        Node(int val, Node* next = nullptr) : val_{val}, next_{next} {}
    };
public:
    // API for iteration
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

    /* CTOR, DTOR, Copy & Move operations */
    ForwardList() = default;
    ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);
    ForwardList(ForwardList&& other);
    ForwardList& operator=(ForwardList&& other);
    ~ForwardList();

    /* Utility */
    size_t size() const;
    bool empty() const;

    /* Access */
    //const Iterator beforeBegin() const;
    Iterator begin() const;
    Iterator end() const;
    int& front();
    int& back();

    /* Modifiers */
    void clear();
    void pushFront(int val);
    void popFront();
    void pushBack(int val);
    void popBack();
    void remove(int val);
    //void eraseAfter(Iterator it);

    /* Print Functions */
    void print() const; 
    void printRec() const; 
    void printReverseRec() const;

    /* Reversal */
    void reverse();
    void reverseRec();
    void reverseStack();

    /* Merge Sort */
    void sort() { sort(head_); }

private:
    void printRec(Node* head) const;
    void printReverseRec(Node* head) const;
    void reverseRec(Node* head);
    void sort(Node*& head);
    Node* merge(Node* left, Node* right);

    Node* head_ = nullptr;
};