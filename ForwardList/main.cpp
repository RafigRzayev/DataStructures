#include <iostream>
#include "forwardlist.hpp"
#include <forward_list>

int main() {
    ForwardList flist;
    flist.pushBack(1);
    flist.pushBack(6);
    flist.pushBack(54);
    flist.pushBack(100);
    flist.pushBack(-5);
    flist.pushFront(-1);
    flist.sort();
    auto flist2(flist);
    flist2.printRec();

    return 0;
}