#include "forwardlist.hpp"
#include <iostream>
#include <stack>

/*************************************** Copy & Move semantics, DTOR  ***************************************/

ForwardList::ForwardList(const ForwardList& other) {
    if(other.empty()) {
        return;
    }
    // create head
    Node* it = other.head_;
    head_ = new Node(it->val_);
    // create other nodes
    Node* prev = head_;
    it = it->next_;
    while(it) {
        Node* cur = new Node(it->val_);
        prev->next_ = cur;
        prev = cur;
        it = it->next_;
    }
}

ForwardList& ForwardList::operator=(const ForwardList& other) {
    if(other.empty()) {
        return *this;
    }
    // create head
    Node* it = other.head_;
    head_ = new Node(it->val_);
    // create other nodes
    Node* prev = head_;
    it = it->next_;
    while(it) {
        Node* cur = new Node(it->val_);
        prev->next_ = cur;
        prev = cur;
        it = it->next_;
    }
    return *this;
}

ForwardList::ForwardList(ForwardList&& other) {
    head_ = other.head_;
    other.head_ = nullptr;
}

ForwardList& ForwardList::operator=(ForwardList&& other) {
    head_ = other.head_;
    other.head_ = nullptr;
    return *this;
}

ForwardList::~ForwardList() {
    clear();
    delete head_;
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

//void ForwardList::eraseAfter(Iterator it) {
//    sentinel->next_ = head_;
//    head_ = sentinel;
//    Node* pos = it.node_;
//    if(!pos || !pos->next_) {
//        head_ = head_->next_;
//        sentinel->next_ = nullptr;
//        return;
//    }
//    Node* cur = pos->next_;
//    Node* next = cur->next_;
//    delete cur;
//    pos->next_ = next;
//    head_ = head_->next_;
//    sentinel->next_ = nullptr;
//}

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
    printRec(head_->next_);
    std::cout << std::endl;
}

void ForwardList::printRec(Node* head) const {
    if(!head) {
        return;
    }
    std::cout << head->val_ << " ";
    printRec(head->next_);
}

void ForwardList::printReverseRec() const {
    printReverseRec(head_->next_);
    std::cout << std::endl;
}

void ForwardList::printReverseRec(Node* head) const {
    if(!head) {
        return;
    }
    printReverseRec(head->next_);
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
    reverseRec(head_->next_);
}

void ForwardList::reverseRec(Node* head) {
    if(!head) {
        return;
    }
    if(!head->next_) {
        head_->next_ = head;
        return;
    }
    reverseRec(head->next_);
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

/*************************************** Sort & Merge ***************************************/   

void ForwardList::sort(Node*& head) {
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
    sort(left);
    sort(right);
    head = merge(left, right);
}

ForwardList::Node* ForwardList::merge(Node* left, Node* right) {
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

