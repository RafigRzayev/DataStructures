#include "forwardlist.hpp"
#include <iostream>
#include <stack>

/*************************************** CTOR, DTOR, Copy, Move   ***************************************/

ForwardList::ForwardList(const ForwardList& other) : ForwardList() {
    copy_(other);
}

ForwardList& ForwardList::operator=(const ForwardList& other) {
    if(this == &other) {
        return *this;
    }
    clear();
    copy_(other);
    return *this;
}

ForwardList::ForwardList(ForwardList&& other) : ForwardList() {
    steal_(std::move(other));
}

ForwardList& ForwardList::operator=(ForwardList&& other) {
    if(this == &other) {
        return *this;
    }
    clear();
    steal_(std::move(other));
    return *this;
}

ForwardList::~ForwardList() {
    clear();
    delete head_;
}

void ForwardList::copy_(const ForwardList& other) {
    Node* it = other.head_->next_;
    Node* prev = head_;
    while(it) {
        prev->next_ = new Node(it->val_);
        prev = prev->next_;
        it = it->next_;
    }
}

void ForwardList::steal_(ForwardList&& other) {
    head_->next_ = other.head_->next_;
    other.head_->next_ = nullptr;
}

/*************************************** Utility  ***************************************/

size_t ForwardList::size() const {
    size_t size{0};
    Node* it = head_->next_;
    while(it) {
        ++size;
        it = it->next_;
    }
    return size;
}

bool ForwardList::empty() const {
    return !head_->next_;
}

/*************************************** Access  ***************************************/

ForwardList::Iterator ForwardList::beforeBegin() const {
    return Iterator(head_);
}

ForwardList::Iterator ForwardList::begin() const {
    return Iterator(head_->next_);
}

ForwardList::Iterator ForwardList::end() const {
    return Iterator();
}

int& ForwardList::front() {
    return head_->next_->val_;
}

int& ForwardList::back() {
    Node* it = head_->next_;
    while(it->next_) {
        it = it->next_;
    }
    return it->val_;
}

/*************************************** Modifiers  ***************************************/

void ForwardList::clear() {
    Node* it = head_->next_;
    while(it) {
        Node* tmp = it->next_;
        delete it;
        it = tmp;
    }
    head_->next_ = nullptr;
}

void ForwardList::pushFront(int val) {
    Node* tmp = new Node{val, head_->next_};
    head_->next_ = tmp;
}

void ForwardList::popFront() {
    if(empty()) {
        return;
    }
    Node* tmp = head_->next_->next_;
    delete head_->next_;
    head_->next_ = tmp;
}

void ForwardList::pushBack(int val) {
    if(empty()) {
        head_->next_ = new Node{val};
        return;
    }
    // get the last element
    Node* it = head_->next_; 
    while(it->next_) {
        it = it->next_;
    }
    it->next_ = new Node(val);
}

void ForwardList::popBack() {
    if(empty()) {
        return;
    }
    if(!head_->next_->next_) {
        delete head_->next_;
        head_->next_ = nullptr;
        return;
    }
    Node* it = head_->next_;
    while(it->next_->next_) {
        it = it->next_;
    }
    delete it->next_;
    it->next_ = nullptr;
}

void ForwardList::remove(int val) {
    Node* prev = head_;
    Node* cur = head_->next_;
    Node* next = nullptr;
    while(cur) {
        next = cur->next_;
        if(cur->val_ == val) {
            delete cur;
            prev->next_ = next;
        } else {
            prev = cur;
        }
        cur = next;
    }
}

void ForwardList::eraseAfter(Iterator it) {
    if(hasAfter_(it)) {
        eraseAfter_(it, Iterator(it.node_->next_->next_));
    }
}

void ForwardList::eraseAfter(Iterator first, Iterator last) {
    if(hasAfter_(first)) {
        eraseAfter_(first, last);
    }
}

void ForwardList::eraseAfter_(Iterator first, Iterator last) {
    if(first == last || first.node_->next_ == last.node_) {
        return;
    }
    Node* end = last.node_;
    Node* prev = first.node_;
    Node* cur = prev->next_;
    while(cur != end) {
        Node* next = cur->next_;
        delete cur;
        cur = next;
    }
    prev->next_ = cur;
}

bool ForwardList::hasAfter_(Iterator it) const {
    return it.node_ && it.node_->next_;
}

void ForwardList::insertAfter(Iterator it, int val) {
    Node* prev = it.node_;
    if(!prev) {
        return;
    }
    Node* next = prev->next_;
    prev->next_ = new Node{val, next};
}


/*************************************** Print Functions ***************************************/

void ForwardList::print() const {
    Node* it = head_->next_;
    while(it) {
        std::cout << it->val_ << " ";
        it = it->next_;
    }
    std::cout << std::endl;
}

void ForwardList::printRec() const {
    printRec_(head_->next_);
    std::cout << std::endl;
}

void ForwardList::printRec_(Node* head) const {
    if(!head) {
        return;
    }
    std::cout << head->val_ << " ";
    printRec_(head->next_);
}

void ForwardList::printReverseRec() const {
    printReverseRec_(head_->next_);
    std::cout << std::endl;
}

void ForwardList::printReverseRec_(Node* head) const {
    if(!head) {
        return;
    }
    printReverseRec_(head->next_);
    std::cout << head->val_ << " ";
}

/*************************************** Reversal ***************************************/

void ForwardList::reverse() {
    Node* cur{head_->next_};
    Node* next{nullptr};
    Node* prev{nullptr};
    while(cur) {
        next = cur->next_;
        cur->next_ = prev;
        prev = cur;
        cur = next;
    }
    head_->next_ = prev;
}

void ForwardList::reverseRec() {
    reverseRec_(head_->next_);
}

void ForwardList::reverseRec_(Node* head) {
    if(!head) {
        return;
    }
    if(!head->next_) {
        head_->next_ = head;
        return;
    }
    reverseRec_(head->next_);
    Node* prev = head->next_;
    prev->next_ = head;
    head->next_ = nullptr;
}

void ForwardList::reverseStack() {
    if(empty()) {
        return;
    }
    Node* it = head_->next_;
    std::stack<Node*> stack;
    while(it->next_) {
        stack.push(it);
        it = it->next_;      
    }
    head_->next_ = it;
    while(!stack.empty()) {
        it->next_ = stack.top();
        stack.pop();
        it = it->next_;
    }
    it->next_ = nullptr;
}

/*************************************** Merge Sort ***************************************/   

void ForwardList::sort() { 
    sort_(head_->next_); 
}

void ForwardList::sort_(Node*& head) {
    if(!head || !head->next_) {
        return;
    }
    // heads of the sub-lists
    Node* left = head;
    Node* right = head;
    // reach the mid point in the main list 
    while(right && right->next_ && right->next_->next_) {
        right = right->next_->next_;
        left = left->next_;
    }
    right = left->next_; // head of the right list
    left->next_ = nullptr; // terminator of the left list
    left = head;
    sort_(left);
    sort_(right);
    head = merge_(left, right);
}

ForwardList::Node* ForwardList::merge_(Node* left, Node* right) {
    Node head{0, nullptr};
    Node* it = &head;
    while(left || right) {
        if(!right) {
            it->next_ = left;
            break;
        }
        if(!left) {
            it->next_ = right;
            break;
        }
        Node*& smallest = left->val_ < right->val_ ? left : right;
        it->next_ = smallest;
        it = it->next_;
        smallest = smallest->next_;
    } 
    return head.next_;
}

