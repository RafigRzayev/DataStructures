#include <iostream>
#include "forwardlist.hpp"
#include <forward_list>

int main() {
    ForwardList flist;
    flist.pushBack(51);
    flist.pushBack(6);
    flist.sort();
    //flist.popBack();
    //flist.popFront();
    flist.sort();
    flist.pushFront(3);
    flist.pushBack(5);
    auto it = flist.beforeBegin();
    flist.insertAfter(it, 5);
    flist.remove(5);
    flist.printRec();
    flist.printReverseRec();
    return 0;
}