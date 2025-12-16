#include "bst.hpp"
#include <algorithm>
#include <queue>

void BST::levelOrder(callback_t cb) {
    if(!head_) {
        return;
    }
    std::queue<Node*> queue;
    queue.push(head_);
    while(!queue.empty()) {
        Node* node = queue.front();
        cb(node->val_);
        queue.pop();
        if(node->left_) {
            queue.push(node->left_);
        }
        if(node->right_) {
            queue.push(node->right_);
        }
    }
}

size_t BST::size_(Node* head) const {
    if(!head) {
        return 0;
    }
    return size_(head->left_) + size_(head->right_) + 1;
}

size_t BST::height_(Node* head) const {
    if(!head) {
        return 0;
    }
    size_t left_height = height_(head->left_);
    size_t right_height = height_(head->right_);
    return std::max(left_height, right_height) + 1;
}

BST::Node* BST::insert_(int val, Node* head) {
    if(!head) {
        return new Node(val);
    }
    if(val <= head->val_) {
        head->left_ = insert_(val, head->left_);
    } else {
        head->right_ = insert_(val, head->right_);
    }
    return head;
}

void BST::preOrder_(Node* head, callback_t cb) {
    if(!head) {
        return;
    }
    cb(head->val_);
    preOrder_(head->left_, cb);
    preOrder_(head->right_, cb);
}

void BST::inOrder_(Node* head, callback_t cb) {
    if(!head) {
        return;
    }
    inOrder_(head->left_, cb);
    cb(head->val_);
    inOrder_(head->right_, cb);
}

void BST::postOrder_(Node* head, callback_t cb) {
    if(!head) {
        return;
    }
    postOrder_(head->left_, cb);
    postOrder_(head->right_, cb);
    cb(head->val_);
}

