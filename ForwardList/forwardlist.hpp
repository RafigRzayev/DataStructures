#pragma once
#include <cstddef>
#include <initializer_list>
#include <functional>

/* Forward List:
 * - Similar API to STL std::forward_list
 * - Implemented via sentinel node at the head. It simplifies eraseAfter() and insertAfter() via beforeBegin() iterator
 * - The exposed first node is always head->next. 
 * - Sentinel is tied to the object and not stolen during move operations
 * - Template version not implement for readability purposes */

using Comp = std::function<bool(int, int)>;

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

    /* CTOR, DTOR, Copy, Move */
    ForwardList();
    ForwardList(std::initializer_list<int> l);
    ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);
    ForwardList(ForwardList&& other);
    ForwardList& operator=(ForwardList&& other);
    ~ForwardList();

    /* Utility */
    size_t size() const;
    bool empty() const;
    bool operator==(const ForwardList& rhs) const;
    bool operator!=(const ForwardList& rhs) const;

    /* Access */
    const Iterator beforeBegin() const;
    Iterator begin() const;
    Iterator end() const;
    int& front();
    int& back();

    /* Modifiers */
    void clear();
    void pushFront(int val);
    void pushBack(int val);
    void popFront();
    void popBack();
    void remove(int val);
    void eraseAfter(Iterator it);
    void eraseAfter(Iterator first, Iterator last);
    void insertAfter(Iterator it, int val);
    void insertAfter(Iterator it, std::initializer_list<int> l);

    /* Print Functions */
    void print() const; 
    void printRec() const; 
    void printReverseRec() const;

    /* Reversal */
    void reverse();
    void reverseRec();
    void reverseStack();

    /* Merge-Sort and Merge */
    void sort(Comp predicate = [](int a, int b){ return a < b; });
    void merge(ForwardList& other, Comp predicate = [](int a, int b) { return a < b; });

private:
    void printRec_(Node* head) const;
    void printReverseRec_(Node* head) const;
    void reverseRec_(Node* head);
    void sort_(Node*& head, Comp& predicate);
    Node* merge_(Node* left, Node* right, Comp& predicate);
    void copy_(const ForwardList& other);
    void steal_(ForwardList&& other);
    void eraseAfter_(Iterator first, Iterator last);
    bool hasAfter_(Iterator it) const;

    Node sentinel_;
    Node* head_;
};