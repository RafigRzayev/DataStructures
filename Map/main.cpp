#include <iostream>
#include "BST.hpp"

int main() {
    BST bst{1, 4, 8, 13, 5, 9, -15, 10, 0, -3, 2};
    bst.remove(0);
    bst.remove(10);
    bst.remove(4);
    bst.insert(3);
    bst.preOrder([](int& val) { std::cout << val << std::endl; });
    return 0;
}