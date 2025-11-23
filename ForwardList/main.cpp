#include <iostream>
#include "forwardlist.hpp"
#include <forward_list>


int main() {


   
    ForwardList flist;
    flist.pushBack(5);
    flist.pushBack(-3);
    flist.pushBack(1);
    flist.pushFront(100);
    flist.pushFront(-5);
    //flist.pushBack(-5);
    //flist.pushBack(6);
    //flist.pushBack(10);
    //flist.print();
    flist.sort();
    flist.printRec();

    return 0;
}