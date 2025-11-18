#include <iostream>
#include "forwardlist.hpp"
#include <list>


int main() {
    ForwardList list;
    //list.pushBack(5);
    //list.pushFront(4);
    //list.pushFront(1);
    //list.pushBack(6);

    //list.pushBack(5);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.reverseStack();
    list.print();
    auto it = list.end();
    for(auto it = list.begin(); it != list.end(); ++it) {
        std:: cout << *it << std::endl;
    }

    std::list<int> list2;list2.

    //list.printReverse();
    //std::list<int> ah; 
    //while(it != end) {
    //    std::cout << *it << std::endl;
    //    ++it;
    //}
}