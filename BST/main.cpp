#include <iostream>
#include "bst.hpp"

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(1);
    bst.insert(2);
    bst.insert(6);
    bst.insert(11);
    bst.insert(-15);
    bst.insert(-10);
    bst.remove(1);
    bst.levelOrder([](int val){ std::cout << val << std::endl; });


}