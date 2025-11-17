#include <iostream>
#include "forwardlist.hpp"

//struct Node {
//    Node(int val = 0, Node* next = nullptr) : val_{val}, next_{next} {}
//    int val_;
//    Node* next_;
//};
//
//class LinkedList {
//public:
//    class Iterator {
//        public:
//            Iterator(Node* node = nullptr) : node_{node} {}
//            int& operator*() { return node_->val_;}
//            Iterator& operator++() { node_ = node_->next_; return *this; }
//            bool operator==(const Iterator& rightIt) const { return node_ == rightIt.node_; }
//            bool operator!=(const Iterator& rightIt) const { return node_ != rightIt.node_; }
//            friend class LinkedList;
//        private: 
//            Node* node_;
//    };
//
//    ~LinkedList() { clear(); }
//    size_t size() const;
//    bool empty() const;
//    void pushFront(int val); 
//    void popFront();
//    void pushBack(int val);
//    void popBack();
//    int& front();
//    int& back();
//    void clear();
//    void reverse();
//    void reverseRecursively() { reverseRecursively(head_); }
//    void print() const { print(head_); }
//    void printReverse() const { printReverse(head_); }
//    void erase(Iterator pos);
//    void erase(Iterator begin, iterator end);
//    void insert(Iterator pos);
//
//    Iterator begin() { return Iterator(head_); }
//    Iterator end() { return Iterator(); }
//private:
//    void print(Node* head) const;
//    void printReverse(Node* head) const;
//    void reverseRecursively(Node* node);
//    Node* head_ = nullptr;
//};
//
//size_t LinkedList::size() const {
//    size_t size = 0;
//    auto it = head_;
//    while(it) {
//        it = it->next_;
//        ++size;
//    }
//    return size;
//}
//
//bool LinkedList::empty() const {
//    return !head_;
//}
//
//void LinkedList::pushFront(int val) {
//    Node* tmp = new Node{val, head_};
//    head_ = tmp;
//}
//
//void LinkedList::popFront() {
//    if(!head_) {
//        return;
//    }
//    Node* tmp = head_->next_;
//    delete head_;
//    head_ = tmp;
//}
//
//void LinkedList::pushBack(int val) {
//    if(!head_) {
//        head_ = new Node{val};
//        return;
//    }
//    Node* it = head_;
//    while(it->next_) {
//        it = it->next_;
//    }
//    it->next_ = new Node{val};
//}
//
//void LinkedList::popBack() {
//    if(!head_) {
//        return;
//    }
//    if(!head_->next_) {
//        delete head_;
//        head_ = nullptr;
//        return;
//    }
//    Node* it = head_;
//    while(it->next_->next_) {
//        it = it->next_;
//    }
//    delete it->next_;
//    it->next_ = nullptr;
//}
//
//int& LinkedList::front() {
//    return head_->val_;
//}
//
//int& LinkedList::back() {
//    Node* it = head_;
//    while(it->next_) {
//        it = it->next_;
//    }
//    return it->val_;
//}
//
//void LinkedList::clear() {
//    Node* it = head_;
//    while(it) {
//        Node* temp = it->next_;
//        delete it;
//        it = temp;
//    }
//    head_ = nullptr;
//}
//
//void LinkedList::reverse() {
//    Node* cur =  head_;
//    Node* prev = nullptr;
//    while(cur) {
//        Node* next = cur->next_;
//        cur->next_ = prev;
//        prev = cur;
//        cur = next;
//    }
//    head_ = prev;
//}
//
//void LinkedList::reverseRecursively(Node* node) {
//    if(!node) {
//        return;
//    }
//    if(!node->next_) {
//        head_ = node;
//        return;
//    }
//    reverseRecursively(node->next_);
//    Node* nextNode = node->next_; 
//    nextNode->next_ = node;
//    node->next_ = nullptr;
//}
//
//void LinkedList::print(Node* head) const {
//    if(!head) {
//        return;
//    }
//    std::cout << head->val_ << " ";
//    print(head->next_);
//}
//
//void LinkedList::printReverse(Node* head) const {
//    if(!head) {
//        return;
//    }
//    printReverse(head->next_);
//    std::cout << head->val_ << " ";
//}

int main() {
    ForwardList list;
    //list.pushBack(5);
    //list.pushFront(4);
    //list.pushFront(1);
    //list.pushBack(6);

    //list.pushBack(5);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.reverseStack();
    list.print();
    auto it = list.end();
    for(auto it = list.begin(); it != list.end(); ++it) {
        std:: cout << *it << std::endl;
    }

    //std::cout << *it << std::endl;

    //list.printReverse();
    //std::list<int> ah; 
    //while(it != end) {
    //    std::cout << *it << std::endl;
    //    ++it;
    //}
}