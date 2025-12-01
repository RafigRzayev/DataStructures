#include <iostream>
#include <cassert>
#include "forwardlist.hpp"

void testClear() {
    std::cout << "test clear(): ";

    ForwardList list1;
    list1.clear();
    assert(list1.empty());

    ForwardList list2{1};
    list2.clear();
    assert(list2.empty());

    ForwardList list3{1, 6};
    list3.clear();
    assert(list3.empty());

    ForwardList list4{6, 9, 12};
    list4.clear();
    assert(list4.empty());

    std::cout << "Passed" << std::endl;
}

void testPushFront() {
    std::cout << "test pushFront(): ";

    ForwardList list;
    list.pushFront(5);
    list.pushFront(15);
    list.pushFront(25);
    assert((list == ForwardList{25, 15, 5}));

    std::cout << "Passed" << std::endl;
}

void testPopFront() {
    std::cout << "test popFront(): ";

    ForwardList list1{1, 3, 5};
    list1.popFront();
    assert((list1 == ForwardList{3, 5}));

    ForwardList list2{1, 3};
    list2.popFront();
    assert((list2 == ForwardList{3}));

    ForwardList list3{5};
    list3.popFront();
    assert((list3.empty()));

    ForwardList list4;
    list4.popFront();
    assert(list4.empty());

    std::cout << "Passed" << std::endl;
}

void testPushBack() {
    std::cout << "test pushBack(): ";

    ForwardList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    assert((list == ForwardList{1,2,3}));

    std::cout << "Passed" << std::endl;
}

void testPopBack() {
    std::cout << "test popBack(): ";

    ForwardList list1{1, 3, 5};
    list1.popBack();
    assert((list1 == ForwardList{1, 3}));

    ForwardList list2{1, 3};
    list2.popBack();
    assert((list2 == ForwardList{1}));

    ForwardList list3{1};
    list3.popBack();
    assert(list3.empty());

    ForwardList list4;
    list4.popBack();
    assert(list4.empty());

    std::cout << "Passed" << std::endl;
}

void testEraseAfter() {
    std::cout << "test EraseAfter(): ";

    // erease after beforeBegin()
    ForwardList list {2, 4, 6};
    auto it = list.beforeBegin();
    list.eraseAfter(it);
    assert((list == ForwardList{4, 6}));
    
    // erease after begin()
    ForwardList list2 {2, 4, 6};
    auto it2 = list2.begin();
    list2.eraseAfter(it2);
    assert((list2 == ForwardList{2, 6}));

    // erease after end()
    ForwardList list3 {2, 4, 6};
    auto it3 = list3.end();
    list3.eraseAfter(it3);
    assert((list3 == ForwardList{2, 4, 6}));

    // erase the last element
    //ForwardList list4 {3, 6, 9, 12};
    //auto it4 = list4.begin();
    //++(++it4); 
    //std::cout << *it4 << std::endl;
    //assert((list4 == ForwardList{3, 6, 9}));

    // erase the mid element
    ForwardList list5 {10, 12, 16, -5, 18};
    auto it5 = list5.begin();
    ++it5;
    assert((list5 == ForwardList{10, 12, -5, 18}));

    // erasing empty list with various iterators

    ForwardList list6;
    list6.eraseAfter(list6.beforeBegin());
    assert(list6 == ForwardList());

    ForwardList list7;
    list7.eraseAfter(list7.begin());
    assert(list7 == ForwardList());

    ForwardList list8;
    list8.eraseAfter(list8.end());
    assert(list8 == ForwardList());

    // ranged erase with the same iterator
    ForwardList list9{5, 50, 565};
    auto start9 = list9.beforeBegin();
    list9.eraseAfter(start9, start9);
    assert((list9 == ForwardList{5, 50, 565}));

    // ranged erase with neighbours
    ForwardList list10{15, 450, 55};
    auto start10 = list10.beforeBegin();
    auto end10 = list10.begin();
    list10.eraseAfter(start10, end10);
    assert((list10 == ForwardList{15, 450, 55}));

    // standard ranged erase A
    ForwardList list11{7, 540, 135, 443};
    auto start11 = list11.beforeBegin();
    auto end11 = ++(list11.begin());
    list11.eraseAfter(start11, end11);
    assert((list11 == ForwardList{540, 135, 443}));

    // standard ranged erase B
    ForwardList list12{113, 24, 65, 89};
    auto start12 = ++(list12.begin());
    auto end12 = list12.end();
    list12.eraseAfter(start12, end12);
    assert((list12 == ForwardList{113, 24}));

    // standard ranged erase C
    ForwardList list13{100, 244, 415, 98};
    auto start13 = list13.beforeBegin();
    auto end13 = list13.end();
    list13.eraseAfter(start13, end13);
    assert(list13.empty());
}
void testInsertAfter() {

}




int main() {
    testClear();
    testPushFront();
    testPopFront();
    testPushBack();
    testPopBack();
    testEraseAfter();
    return 0;
}