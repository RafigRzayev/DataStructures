#pragma once

#include "bst.hpp"
#include <utility>
#include <cstddef>
#include <iostream>
#include <functional>

template<typename K, typename V, typename KeyComp = std::less<K>>
class Map {
public:
    using val_t = std::pair<K, V>;
    struct ValueComp {
        KeyComp keyComp;
        bool operator()(const val_t& lhs, const val_t& rhs) const {
            return keyComp(lhs.first, rhs.first);
        }
        bool operator()(const val_t& lhs, const K& rhs) const {
            return keyComp(lhs.first, rhs);
        }
        bool operator()(const K& lhs, const val_t& rhs) const {
            return keyComp(lhs, rhs.first);
        }
    };
public:
    bool empty() const { return bst.empty();}
    size_t size() const { return bst.size(); }
    bool contains(const K& key) const { return bst.search(key);}
    void insert(const val_t& val) { bst.insert(val); }
    void erase(const K& key) { bst.remove(key); };
    void clear() { bst.clear(); }   
    KeyComp GetKeyComp() const { return KeyComp(); }
    ValueComp GetValueComp() const { return ValueComp(); }
    //void forEach(callback_t f);

    void print();
private:

    BST<val_t, ValueComp> bst;
};

template<typename K, typename V, typename KeyComp>
void Map<K,V, KeyComp>::print() {
    bst.inOrder([](val_t& el) { std::cout << el.first << " " << el.second << "\n"; });
}

