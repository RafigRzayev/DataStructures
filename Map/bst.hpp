#pragma once 

#include <cstddef>
#include <initializer_list>
#include <optional>
#include <algorithm>
#include <functional>
#include <queue>

template <typename T, typename Compare = std::less<T>>
class BST {
    using cb_t = std::function<void(T&)>;
    Compare comp;
    bool equals(const T& a, const T&b) const { return !comp(a, b) && !comp(b,a);}
    bool less(const T& a, const T&b) const { return comp(a, b);}
    bool greater(const T& a, const T&b) const { return comp(b, a);}
private:
    struct Node {
        T val;
        Node* left;
        Node* right;
        Node(T val, Node* left = nullptr, Node* right = nullptr) : val{val}, left{left}, right{right} {}
    };
public:
    BST() = default;
    BST(std::initializer_list<T> list);
    BST(const BST& rhs);
    BST(BST&& rhs) noexcept;
    BST& operator=(const BST& rhs);
    BST& operator=(BST&& rhs) noexcept;
    ~BST();

    bool empty() const { return !root_; }
    size_t size() const { return size_(root_); }
    size_t height() const { return height_(root_);}
    bool search(const T& val) const { return search_(val, root_);}
    std::optional<T> min() const;
    std::optional<T> max() const;

    void insert(const T& val) { root_ = insert_(val, root_); }
    void remove(const T& val) { root_ = remove_(val, root_); }
    void clear();

    void preOrder(cb_t cb) { preOrder_(cb, root_); }
    void inOrder(cb_t cb) { inOrder_(cb, root_); }
    void postOrder(cb_t cb) { postOrder_(cb, root_); }
    void levelOrder(cb_t cb);
private:
    size_t size_(const Node* root) const;
    size_t height_(const Node* root) const;
    bool search_(const T& val, const Node* root) const;
    Node* insert_(const T& val, Node* root);
    Node* remove_(const T& val, Node* root);
    void clear_(Node* root);
    Node* clone_(const Node* root);

    void preOrder_(cb_t cb, Node* root);
    void inOrder_(cb_t cb, Node* root);
    void postOrder_(cb_t cb, Node* root);

    Node* root_ = nullptr;
};

/* -------------------------------------------------- CTOR/DTOR/Copy/Move -------------------------------------------------- */

// user-defined CTOR
template<typename T, typename Compare>
BST<T, Compare>::BST(std::initializer_list<T> list) {
    for(auto& e : list) {
        insert(e);
    }
}

// copy CTOR
template<typename T, typename Compare>
BST<T, Compare>::BST(const BST& rhs) : root_{clone_(rhs.root_)} { }

// move CTOR
template<typename T, typename Compare>
BST<T, Compare>::BST(BST&& rhs) noexcept : root_{rhs.root_} {
    rhs.root_ = nullptr;
}

// copy assignment
template<typename T, typename Compare>
BST<T, Compare>& BST<T, Compare>::operator=(const BST& rhs) {
    if(this == &rhs) {
        return *this;
    }
    clear();
    root_ = clone_(rhs.root_);
    return *this;
}

// move assignment
template<typename T, typename Compare>
BST<T, Compare>& BST<T, Compare>::operator=(BST&& rhs) noexcept {
    if(this == &rhs) {
        return *this;
    }
    clear();
    root_ = rhs.root_;
    rhs.root_ = nullptr;
    return *this;
}

// DTOR
template<typename T, typename Compare>
BST<T, Compare>::~BST() {
    clear();
}

/* -------------------------------------------------- Utility -------------------------------------------------- */

template<typename T, typename Compare>
size_t BST<T, Compare>::size_(const Node* root) const {
    if(!root) {
        return 0;
    }
    size_t leftSize = size_(root->left);
    size_t rightSize = size_(root->right);
    return leftSize + rightSize + 1;
}

template<typename T, typename Compare>
size_t BST<T, Compare>::height_(const Node* root) const {
    if(!root) {
        return 0;
    }
    size_t leftHeight = height_(root->left);
    size_t rightHeight = height_(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

template<typename T, typename Compare>
bool BST<T, Compare>::search_(const T& val, const Node* root) const {
    if(!root) {
        return false;
    }
    if(equals(val, root->val)) {
        return true;
    }
    return search_(val, less(val, root->val) ? root->left : root->right);
}

template<typename T, typename Compare>
std::optional<T> BST<T, Compare>::min() const {
    // empty tree case
    if(!root_) {
        return std::nullopt;
    }
    // find mininmum
    const Node* it = root_;
    while(it->left) {
        it = it->left;
    }
    return it->val;
}

template<typename T, typename Compare>
std::optional<T> BST<T, Compare>::max() const {
    // empty tree case
    if(!root_) {
        return std::nullopt;
    }
    // find maximum
    const Node* it = root_;
    while(it->right) {
        it = it->right;
    }
    return it->val;
}

/* -------------------------------------------------- Modifiers -------------------------------------------------- */

template<typename T, typename Compare>
typename BST<T, Compare>::Node* BST<T, Compare>::insert_(const T& val, Node* root) {
    if(!root) {
        return new Node{val};
    }
    if(equals(val, root->val)) {
        return root;
    }
    else if(less(val, root->val)) {
        root->left = insert_(val, root->left);
    } 
    else {
        root->right = insert_(val, root->right);
    }
    return root;
}

template<typename T, typename Compare>
typename BST<T, Compare>::Node* BST<T, Compare>::remove_(const T& val, Node* root) {
    if(!root) {
        return nullptr;
    }
    if(less(val, root->val)) {
        root->left = remove_(val, root->left);
    } 
    else if(greater(val, root->val)) {
        root->right = remove_(val, root->right);
    }
    else {
        // Case 1: 0 children
        if(!root->left && !root->right) {
            delete root;
            root = nullptr;
        }
        // Case 2: 1 child
        else if(!root->left && root->right) {
            Node* tmp = root->right;
            delete root;
            root = tmp;
        } 
        else if(root->left && !root->right){
            Node* tmp = root->left;
            delete root;
            root = tmp;
        }
        // Case 3: 2 children
        else {
            // find minimum in the right sub-tree
            Node* it = root->right;
            while(it->left) {
                it = it->left;
            }
            root->val = it->val;
            root->right = remove_(it->val, root->right);
        }
    }
    return root;
}

template<typename T, typename Compare>
void BST<T, Compare>::clear() {
    clear_(root_);
    root_ = nullptr;
}

template<typename T, typename Compare>
void BST<T, Compare>::clear_(Node* root) {
    if(!root) {
        return;
    }
    clear_(root->left);
    clear_(root->right);
    delete root;
}

/* -------------------------------------------------- Traversal -------------------------------------------------- */

template<typename T, typename Compare>
void BST<T, Compare>::preOrder_(cb_t cb, Node* root) {
    if(!root) {
        return;
    }
    cb(root->val);
    preOrder_(cb, root->left);
    preOrder_(cb, root->right);
}

template<typename T, typename Compare>
void BST<T, Compare>::inOrder_(cb_t cb, Node* root) {
    if(!root) {
        return;
    }
    inOrder_(cb, root->left);
    cb(root->val);
    inOrder_(cb, root->right);
}

template<typename T, typename Compare>
void BST<T, Compare>::postOrder_(cb_t cb, Node* root) {
    if(!root) {
        return;
    }
    postOrder_(cb, root->left);
    postOrder_(cb, root->right);
    cb(root->val);
}

template<typename T, typename Compare>
void BST<T, Compare>::levelOrder(cb_t cb) {
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

/* -------------------------------------------------- Other -------------------------------------------------- */

template<typename T, typename Compare>
typename BST<T, Compare>::Node* BST<T, Compare>::clone_(const Node* root) {
    if(!root) {
        return nullptr;
    }
    Node* tmp = new Node{root->val};
    tmp->left = clone_(root->left);
    tmp->right = clone_(root->right);
    return tmp;
}