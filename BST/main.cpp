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
    //bst.levelOrder([](int val){ std::cout << val << std::endl; });
    bst.clear();

    bst.levelOrder([](int& val){ std::cout << val << std::endl; });
    if(bst.empty()) std::cout << "empty" << std::endl;
    std::cout << bst.size() << std::endl;
    BST bst2{3, 5, -3, 10, 12, 12, 8, -5};
    bst2.levelOrder([](int& val){ std::cout << val << std::endl; });

}