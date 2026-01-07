#pragma once

#include <cstddef>
#include <initializer_list>
#include <functional>

/*
    Binary Search Tree class needed for Map implementation
  - Doesn't allow duplicates
  - Not self-balancing for the moment (AVL / RBT will be added later)
  - Non-template implementation for readability
*/

using callback_t = std::function<void(int&)>;

class BST {
private:
    struct Node { 
        int val;
        Node* left;
        Node* right;
        Node(int val = 0, Node* left = nullptr, Node* right = nullptr) : val{val}, left{left}, right{right} {}
    };
public:
    BST() = default;
    BST(std::initializer_list<int> list);
    BST(const BST& rhs);
    BST& operator=(const BST& rhs);
    BST(BST&& rhs) noexcept;
    BST& operator=(BST&& rhs) noexcept;
    ~BST();

    bool empty() const { return !root_;}
    int min() const { return min(root_); }
    int max() const;
    size_t size() const { return size(root_); }
    size_t height() const { return height(root_); }
    bool search(int val) const { return search(val, root_); }
    void insert(int val) { root_ = insert(val, root_); }
    void remove(int val) { root_ = remove(val, root_); }
    void clear() { clear(root_); root_ = nullptr; }

    void preOrder(callback_t cb) { preOrder(root_, cb); }
    void inOrder(callback_t cb) { inOrder(root_, cb); }
    void postOrder(callback_t cb) { postOrder(root_, cb); }
    void levelOrder(callback_t cb);
    
private:
    size_t size(Node* root) const;
    int min(Node* root) const;
    size_t height(Node* root) const;
    bool search(int val, Node* root) const;
    Node* insert(int val, Node* root);
    Node* remove(int val, Node* root); 
    void clear(Node* root);
    Node* clone(const Node* root);
    void preOrder(Node* root, callback_t cb);
    void inOrder(Node* root, callback_t cb);
    void postOrder(Node* root, callback_t cb);

    Node* root_ = nullptr;
};