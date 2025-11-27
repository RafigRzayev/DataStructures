#pragma once
#include <cstddef>
#include <initializer_list>

/* Forward List:
 * - Similar API to STL std::forward_list
 * - Implemented via sentinel node at the head. It simplifies eraseAfter() and insertAfter() via beforeBegin() iterator
 * - The exposed first node is always head->next. 
 * - Sentinel is tied to the object and not stolen during move operations
 * 
 * TODO:
 * 1) Switch to template and caution for pass by value
 * 2) Exceptions for front/back?
 * 
 * 4) Tests? 
 * 5) Refactor/verify
 * 6) Consider sentinel creation without utilizing new operator
 * 7) Investigate universal reference for copy_()
 * 8) Expose merge?
 * 9) Reverse without head_ node? 
 * 10) Sort predicate
 */

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
    ForwardList() = default;
    ForwardList(std::initializer_list<int> l);
    ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);
    ForwardList(ForwardList&& other);
    ForwardList& operator=(ForwardList&& other);
    ~ForwardList();

    /* Utility */
    size_t size() const;
    bool empty() const;

    /* Access */
    Iterator beforeBegin() const;
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

    /* Merge Sort */
    void sort();

private:
    void printRec_(Node* head) const;
    void printReverseRec_(Node* head) const;
    void reverseRec_(Node* head);
    void sort_(Node*& head);
    Node* merge_(Node* left, Node* right);
    void copy_(const ForwardList& other);
    void steal_(ForwardList&& other);
    void eraseAfter_(Iterator first, Iterator last);
    bool hasAfter_(Iterator it) const;
    Node* head_ = new Node{};
};