#include <iostream>
#include "forwardlist.hpp"
#include <forward_list>


int main() {
    ForwardList list;
    //list.pushBack(5);
    //list.pushFront(4);
    //list.pushFront(1);
    //list.pushBack(6);

    //list.pushBack(5);
    list.pushBack(1);
   list.pushBack(2);


    list.remove(2);
        list.remove(1);
        list.pushFront(2);
    list.print();

    std::forward_list<int>flist;
    //list.printReverse();
    
    //while(it != end) {
    //    std::cout << *it << std::endl;
    //    ++it;
    //}
}