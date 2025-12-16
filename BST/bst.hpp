#pragma once

#include <functional>

using callback_t = std::function<void(int)>;

class BST {
private:
    struct Node {
        Node* left_;
        Node* right_;
        int val_;
        Node(int val = 0, Node* left = nullptr, Node* right = nullptr) : val_{val}, left_{left}, right_{right} {}
    };
public:
    bool empty() const { return !head_;}
    size_t size() const { return size_(head_); }
    int min() const;
    int max() const;
    size_t height() const { return height_(head_); }
    bool search(int val) const { return search_(val, head_);}
    void insert(int val) { head_ = insert_(val, head_); }
    void remove(int val) { head_ = remove_(val, head_); }
    void preOrder(callback_t cb) { preOrder_(head_, cb); }
    void inOrder(callback_t cb) { inOrder_(head_, cb); }
    void postOrder(callback_t cb) { postOrder_(head_, cb); }
    void levelOrder(callback_t cb);
private:
    size_t size_(Node* head) const;
    size_t height_(Node* head) const;
    bool search_(int val, Node* head) const;
    Node* insert_(int val, Node* head);
    Node* remove_(int val, Node* head);
    void preOrder_(Node* head, callback_t cb);
    void inOrder_(Node* head, callback_t cb);
    void postOrder_(Node* head, callback_t cb);
    Node* head_ = nullptr;
};