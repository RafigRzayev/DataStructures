#pragma once

#include "bst.hpp"

template<typename K, typename V>
class Map {
    using val_t = std::pair<K, V>;
public:
    void insert(const val_t& val);
    void erase(const K& key);
private:
    BST<val_t> bst;
};

template<typename K, typename V>
void Map<K,V>::insert(const val_t& val) {
    bst.insert(val);
}

template<typename K, typename V>
void Map<K,V>::erase(const K& key) {
    bst.remove();
}