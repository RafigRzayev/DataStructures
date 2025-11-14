#include "forwardlist.hpp"
#include <iostream>

size_t ForwardList::size() const {
    size_t size{0};
    Node* it = head_;
    while(it) {
        ++size;
        it = it->next_;
    }
    return size;
}

bool ForwardList::empty() const {
    return !head_;
}

void ForwardList::clear() {
    Node* it = head_;
    while(it) {
        Node* tmp = it->next_;
        delete it;
        it = tmp;
    }
}

void ForwardList::pushFront(int val) {
    Node* tmp = new Node{val, head_};
    head_ = tmp;
}

void ForwardList::pushBack(int val) {
    if(empty()) {
        head_ = new Node{val};
        return;
    }
    // get the last element
    Node* it = head_; 
    while(it->next_) {
        it = it->next_;
    }
    it->next_ = new Node(val);
}

void ForwardList::popFront() {
    if(empty()) {
        return;
    }
    Node* tmp = head_->next_;
    delete head_;
    head_ = tmp;
}

void ForwardList::popBack() {
    if(empty()) {
        return;
    }
    if(!head_->next_) {
        delete head_;
        head_ = nullptr;
        return;
    }
    Node* it = head_;
    while(it->next_->next_) {
        it = it->next_;
    }
    delete it->next_;
    it->next_ = nullptr;
}

/*************************************** Print Functions ***************************************/

void ForwardList::print() const {
    Node* it = head_;
    while(it) {
        std::cout << it->val_ << " ";
        it = it->next_;
    }
    std::cout << std::endl;
}

void ForwardList::printRec() const {
    printRec(head_);
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
    printReverseRec(head_);
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
    Node* cur{head_};
    Node* prev{nullptr};
    Node* next{nullptr};
    while(cur) {
        next = cur->next_;
        cur->next_ = prev;  
        prev = cur;
        cur = next;
    }
    head_ = prev;
}

//void ForwardList::reverseRec(Node* head) {
//    if(!head) {
//        return;
//    }
//
//}
