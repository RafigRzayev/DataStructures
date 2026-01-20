#pragma once 

#include <cstddef>
#include <initializer_list>
#include <optional>
#include <algorithm>
#include <functional>
#include <queue>

template <typename T, typename Comp = std::less<T>>
class BST {
    using cb_t = std::function<void(T&)>;
    Comp comp;
    bool equals(const T& a, const T&b) const { return !comp(a, b) && !comp(b,a);}
    bool less(const T& a, const T&b) const { return comp(a, b);}
    bool greater(const T& a, const T&b) const { return comp(b, a);}

    struct Node {
        T val;
        Node* left;
        Node* right;
        Node* parent;
        Node(T val, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) : val{val}, parent{parent}, left{left}, right{right}  {}
    };
public:
    class Iterator {
    public:
        Iterator(Node* node) : node_{node} {}
        T& operator*() { return node_->val;}  
        Iterator& operator++() { node_ = inOrderSuccessor(node_); return *this; }
        Iterator& operator--() { node_ = inOrderPredecessor(node_); return *this; }
        bool operator==(const Iterator& rhs) const { return node_ == rhs.node_; }
        bool operator!=(const Iterator& rhs) const { return node_ != rhs.node_; }

    private:
        Node* node_ = nullptr;
    };


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

    template<typename U>
    bool search(const U& x) const { return search_(x, root_);}
    std::optional<T> min() const;
    std::optional<T> max() const;

    void insert(const T& val) { root_ = insert_(val, root_); }
    template<typename U>
    void remove(const U& x) { root_ = remove_(x, root_); }
    void clear();

    void preOrder(cb_t cb) { preOrder_(cb, root_); }
    void inOrder(cb_t cb) { inOrder_(cb, root_); }
    void postOrder(cb_t cb) { postOrder_(cb, root_); }
    void levelOrder(cb_t cb);
private:
    size_t size_(const Node* root) const;
    size_t height_(const Node* root) const;
    template<typename U>
    bool search_(const U& x, const Node* root) const;
    Node* insert_(const T& val, Node* root, Node* parent = nullptr);
    template<typename U>
    Node* remove_(const U& x, Node* root);
    void clear_(Node* root);
    Node* clone_(const Node* root, const Node* parent = nullptr);

    Node* inOrderSuccessor(const Node* root) const; 
    Node* inOrderPredecessor(const Node* root) const { return nullptr; } // in progress
    void preOrder_(cb_t cb, Node* root);
    void inOrder_(cb_t cb, Node* root);
    void postOrder_(cb_t cb, Node* root);

    Node* root_ = nullptr;
};

/* -------------------------------------------------- CTOR/DTOR/Copy/Move -------------------------------------------------- */

// user-defined CTOR
template<typename T, typename Comp>
BST<T, Comp>::BST(std::initializer_list<T> list) {
    for(auto& e : list) {
        insert(e);
    }
}

// copy CTOR
template<typename T, typename Comp>
BST<T, Comp>::BST(const BST& rhs) : root_{clone_(rhs.root_)} { }

// move CTOR
template<typename T, typename Comp>
BST<T, Comp>::BST(BST&& rhs) noexcept : root_{rhs.root_} {
    rhs.root_ = nullptr;
}

// copy assignment
template<typename T, typename Comp>
BST<T, Comp>& BST<T, Comp>::operator=(const BST& rhs) {
    if(this == &rhs) {
        return *this;
    }
    clear();
    root_ = clone_(rhs.root_);
    return *this;
}

// move assignment
template<typename T, typename Comp>
BST<T, Comp>& BST<T, Comp>::operator=(BST&& rhs) noexcept {
    if(this == &rhs) {
        return *this;
    }
    clear();
    root_ = rhs.root_;
    rhs.root_ = nullptr;
    return *this;
}

// DTOR
template<typename T, typename Comp>
BST<T, Comp>::~BST() {
    clear();
}

/* -------------------------------------------------- Utility -------------------------------------------------- */

template<typename T, typename Comp>
size_t BST<T, Comp>::size_(const Node* root) const {
    if(!root) {
        return 0;
    }
    size_t leftSize = size_(root->left);
    size_t rightSize = size_(root->right);
    return leftSize + rightSize + 1;
}

template<typename T, typename Comp>
size_t BST<T, Comp>::height_(const Node* root) const {
    if(!root) {
        return 0;
    }
    size_t leftHeight = height_(root->left);
    size_t rightHeight = height_(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

template<typename T, typename Comp>
template<typename U>
bool BST<T, Comp>::search_(const U& x, const Node* root) const {
    if(!root) {
        return false;
    }
    if(!comp(x, root->val) && !comp(root->val, x)) {
        return true;
    }
    return search_(x, comp(x, root->val) ? root->left : root->right);
}

template<typename T, typename Comp>
std::optional<T> BST<T, Comp>::min() const {
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

template<typename T, typename Comp>
std::optional<T> BST<T, Comp>::max() const {
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

template<typename T, typename Comp>
typename BST<T, Comp>::Node* BST<T, Comp>::insert_(const T& val, Node* root, Node* parent) {
    if(!root) {
        return new Node{val, parent};
    }
    if(equals(val, root->val)) {
        return root;
    }
    else if(less(val, root->val)) {
        root->left = insert_(val, root->left, root);
    } 
    else {
        root->right = insert_(val, root->right, root);
    }
    return root;
}

template<typename T, typename Comp>
template<typename U>
typename BST<T, Comp>::Node* BST<T, Comp>::remove_(const U& x, Node* root) {
    if(!root) {
        return nullptr;
    }
    if(comp(x, root->val)) {
        root->left = remove_(x, root->left);
    } 
    else if(comp(root->val, x)) {
        root->right = remove_(x, root->right);
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
            tmp->parent = root->parent;
            delete root;
            root = tmp;
        } 
        else if(root->left && !root->right){
            Node* tmp = root->left;
            tmp->parent = root->parent;
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

template<typename T, typename Comp>
void BST<T, Comp>::clear() {
    clear_(root_);
    root_ = nullptr;
}

template<typename T, typename Comp>
void BST<T, Comp>::clear_(Node* root) {
    if(!root) {
        return;
    }
    clear_(root->left);
    clear_(root->right);
    delete root;
}

/* -------------------------------------------------- Traversal -------------------------------------------------- */

template<typename T, typename Comp>
void BST<T, Comp>::preOrder_(cb_t cb, Node* root) {
    if(!root) {
        return;
    }
    cb(root->val);
    preOrder_(cb, root->left);
    preOrder_(cb, root->right);
}

template<typename T, typename Comp>
void BST<T, Comp>::inOrder_(cb_t cb, Node* root) {
    if(!root) {
        return;
    }
    inOrder_(cb, root->left);
    cb(root->val);
    inOrder_(cb, root->right);
}

template<typename T, typename Comp>
void BST<T, Comp>::postOrder_(cb_t cb, Node* root) {
    if(!root) {
        return;
    }
    postOrder_(cb, root->left);
    postOrder_(cb, root->right);
    cb(root->val);
}

template<typename T, typename Comp>
void BST<T, Comp>::levelOrder(cb_t cb) {
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

template<typename T, typename Comp>
typename BST<T, Comp>::Node* BST<T, Comp>::inOrderSuccessor(const Node* root) const {
    if(!root) {
        return nullptr;
    }
    // Case 1: has right sub-tree
    if(root->right)  {
        // find left-most element in the right sub-tree
        Node* it = root->right;
        while(it->left) {
            it = it->left;
        }
        return it;
    } else {
        // is to the left of the parent
        if(less(root->val, root->parent->val)) {
            return root->parent;
        }
        // is to the right of the parent 
        else {
            Node* parent = root->parent;
            while(parent && greater(root->val, parent->val)) {
                parent = parent->parent;
            }
            return parent;
        }
    }
}

template<typename T, typename Comp>
typename BST<T, Comp>::Node* BST<T, Comp>::inOrderPredecessor(const Node* root) const {

}

/* -------------------------------------------------- Other -------------------------------------------------- */

template<typename T, typename Comp>
typename BST<T, Comp>::Node* BST<T, Comp>::clone_(const Node* root, const Node* parent) {
    if(!root) {
        return nullptr;
    }
    Node* tmp = new Node{root->val, parent};
    tmp->left = clone_(root->left, tmp);
    tmp->right = clone_(root->right, tmp);
    return tmp;
}