#include <iostream>
#include <list>
struct Node {
    Node(int val = 0, Node* next = nullptr) : val_{val}, next_{next} {}
    int val_;
    Node* next_;
};

class LinkedList {
public:
    class Iterator {
        public:
            Iterator(Node* node = nullptr) : node_{node} {}
            int& operator*() { return node_->val_;}
            Iterator& operator++() { node_ = node_->next_; return *this; }
            bool operator==(const Iterator& rightIt) const { return node_ == rightIt.node_; }
            bool operator!=(const Iterator& rightIt) const { return node_ != rightIt.node_; }
            friend class LinkedList;
        private: 
            Node* node_;
    };

    size_t size() const;
    bool empty() const;
    void pushFront(int val); 
    void popFront();
    void pushBack(int val);
    void popBack();
    int front();
    int back();
    void clear();
    void reverse();

    Iterator begin() { return Iterator(head_); }
    Iterator end() { return Iterator(); }
private:
    Node* head_ = nullptr;
};

size_t LinkedList::size() const {
    size_t size = 0;
    auto it = head_;
    while(it) {
        it = it->next_;
        ++size;
    }
    return size;
}

bool LinkedList::empty() const {
    return !head_;
}

void LinkedList::pushFront(int val) {
    Node* tmp = new Node{val, head_};
    head_ = tmp;
}

void LinkedList::popFront() {
    if(!head_) {
        return;
    }
    Node* tmp = head_->next_;
    delete head_;
    head_ = tmp;
}

void LinkedList::pushBack(int val) {
    if(!head_) {
        head_ = new Node{val};
        return;
    }
    Node* it = head_;
    while(it->next_) {
        it = it->next_;
    }
    it->next_ = new Node{val};
}

void LinkedList::popBack() {
    if(!head_) {
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

int main() {
    LinkedList list;
    list.pushBack(5);
    list.popBack();
    list.pushFront(3);
    list.popFront();
    list.pushFront(1);
    list.pushBack(0);
        list.pushBack(5);
            list.pushBack(14);
            list.popFront();
    LinkedList::Iterator it = list.begin();
    auto end = list.end();
    while(it != end) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> la;
}