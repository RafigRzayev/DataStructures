#pragma once

#include "bst.hpp"
#include <utility>
#include <cstddef>
#include <iostream>

template<typename K, typename V>
class Map {
    using val_t = std::pair<K, V>;
private:
    struct Comp {
        bool operator()(const std::pair<K, V>& lhs, const std::pair<K, V>& rhs) const {
            return lhs.first < rhs.first;
        }
    };
public:
    bool empty() const { return bst.empty();}
    size_t size() const { return bst.size(); }
    bool contains(const K& key) const { return bst.search(std::make_pair(key, V{}));}
    void insert(const val_t& val) { bst.insert(val); }
    void erase(const K& key) { bst.remove(std::make_pair(key, V{}))};
    void clear() { bst.clear(); }
    

    void print();
private:

    BST<val_t, Comp> bst;
};

template<typename K, typename V>
void Map<K,V>::print() {
    bst.inOrder([](val_t& el) { std::cout << el.first << " " << el.second << "\n"; });
}

