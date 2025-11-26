#include <iostream>
#include "forwardlist.hpp"
#include <forward_list>

int main() {
    ForwardList flist;
    flist.pushBack(51);
    flist.pushBack(6);

    flist.sort();

    ForwardList flist2{flist};
    flist2.eraseAfter(flist2.beforeBegin());
    flist = flist2;
    flist.print();
    flist2.print();
    return 0;
}