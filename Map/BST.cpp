#include "BST.hpp"
#include <cstddef>
#include <algorithm>
#include <cassert>
#include <queue>

BST::BST(std::initializer_list<int> list) {
    for(auto i : list) {
        insert(i);
    }
}

BST::BST(const BST& rhs) : root_{clone_(rhs.root_)} { }

BST& BST::operator=(const BST& rhs) {
    if(this == &rhs) {
        return *this;
    }
    clear();
    root_ = clone_(rhs.root_);
    return *this;
}

BST::BST(BST&& rhs) noexcept : root_{rhs.root_} {
    rhs.root_ = nullptr;
}

BST& BST::operator=(BST&& rhs) noexcept {
    if(this == &rhs) {
        return *this;
    }
    clear();
    root_ = rhs.root_;
    rhs.root_ = nullptr;
    return *this;
}

BST::~BST() {
    clear();
}

BST::Node* BST::clone_(const Node* root) {
    if(!root) {
        return nullptr;
    }
    Node* tmp = new Node{root->val};
    tmp->left = clone_(root->left);
    tmp->right = clone_(root->right);
    return tmp;
}

int BST::min(Node* root) const {
    assert(root);
    if(!root->left) {
        return root->val;
    }
    return min(root->left);
}

// non-recursive
int BST::max() const {
    Node* it = root_;
    assert(it);
    while(it->right) {
        it = it->right;
    }
    return it->val;
}

size_t BST::size(Node* root) const {
    if(!root) {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

size_t BST::height(Node* root) const {
    if(!root) {
        return 0;
    }
    const size_t leftHeight = height(root->left);
    const size_t rightHeight = height(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

bool BST::search(int val, Node* root) const {
    if(!root) {
        return false;
    }
    if(root->val == val) {
        return true;
    }
    return search(val, (val <= root->val ? root->left : root->right));
}

BST::Node* BST::insert(int val, Node* root) {
    if(!root) {
        return new Node(val);
    }
    if(val <= root->val) {
        root->left = insert(val, root->left);
    } else {
        root->right = insert(val, root->right);
    }
    return root;
}

BST::Node* BST::remove(int val, Node* root) {
    if(!root) {
        return root;
    }
    if(val < root->val) {
        root->left = remove(val, root->left);
    } 
    else if(val > root->val) {
        root->right = remove(val, root->right);
    } 
    else {
        // Case 1: 0 children
        if(!root->left && !root->right) {
            delete root;
            root = nullptr;
        }
        // Case 2: 1 child 
        else if(root->left && !root->right) {
            Node* tmp = root->left;
            delete root;
            root = tmp;
        }
        else if(!root->left && root->right) {
            Node* tmp = root->right;
            delete root;
            root = tmp;
        }
        // Case 3: 2 children
        else {
            // find the smallest node in the right sub-tree
            Node* it = root->right;
            while(it->left) {
                it = it->left;
            }
            root->val = it->val;
            root->right = remove(it->val, root->right);
        }
    }
    return root;
}

void BST::clear(Node* root) {
    if(!root) {
        return;
    }
    clear(root->left);
    clear(root->right);
    delete root;
}

void BST::preOrder(Node* root, callback_t cb) {
    if(!root) {
        return;
    }
    cb(root->val);
    preOrder(root->left, cb);
    preOrder(root->right, cb);
}

void BST::inOrder(Node* root, callback_t cb) {
    if(!root) {
        return;
    }
    inOrder(root->left, cb);
    cb(root->val);
    inOrder(root->right, cb);
}

void BST::postOrder(Node* root, callback_t cb) {
    if(!root) {
        return;
    }
    postOrder(root->left, cb);
    postOrder(root->right, cb);
    cb(root->val);
}

void BST::levelOrder(callback_t cb) {
    if(!root_) {
        return;
    }
    std::queue<Node*> queue;
    queue.push(root_);
    while(!queue.empty()) {
        Node* it = queue.front();
        cb(it->val);
        if(it->left) {
            queue.push(it->left);
        }
        if(it->right) {
            queue.push(it->right);
        }
        queue.pop();
    }
}