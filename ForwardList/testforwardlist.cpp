#include <iostream>
#include <cassert>
#include "forwardlist.hpp"

void testClear() {
    std::cout << "test clear(): ";

    {
        ForwardList list;
        list.clear();
        assert(list.empty());
    }

    {
        ForwardList list = {1};
        list.clear();
        assert(list.empty());
    }

    {
        ForwardList list = {1, 2};
        list.clear();
        assert(list.empty());
    }

    {
        ForwardList list = {1, 2, 3};
        list.clear();
        assert(list.empty());
    }

    {
        ForwardList list = {1, 2, 3, 4};
        list.clear();
        assert(list.empty());
    }

    {
        ForwardList list = {1, 2, 3, 4, 5};
        list.clear();
        assert(list.empty());
    }

    std::cout << "Passed" << std::endl;
}

void testPushFront() {
    std::cout << "test pushFront(): ";

    {
        ForwardList list;
        list.pushFront(8);
        assert((list == ForwardList{8}));
    }

    {
        ForwardList list = {1};
        list.pushFront(8);
        assert((list == ForwardList{8, 1}));
    }

    {
        ForwardList list = {1, 2};
        list.pushFront(8);
        assert((list == ForwardList{8, 1, 2}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.pushFront(8);
        assert((list == ForwardList{8, 1, 2, 3}));
    }

    {
        ForwardList list = {1, 2, 3, 4};
        list.pushFront(8);
        assert((list == ForwardList{8, 1, 2, 3, 4}));
    }

    {
        ForwardList list = {1, 2, 3, 4, 5};
        list.pushFront(8);
        assert((list == ForwardList{8, 1, 2, 3, 4, 5}));
    }

    std::cout << "Passed" << std::endl;
}

void testPushBack() {
    std::cout << "test pushBack(): ";

    {
        ForwardList list;
        list.pushBack(8);
        assert((list == ForwardList{8}));
    }

    {
        ForwardList list = {1};
        list.pushBack(8);
        assert((list == ForwardList{1, 8}));
    }

    {
        ForwardList list = {1, 2};
        list.pushBack(8);
        assert((list == ForwardList{1, 2, 8}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.pushBack(8);
        assert((list == ForwardList{1, 2, 3, 8}));
    }

    {
        ForwardList list = {1, 2, 3, 4};
        list.pushBack(8);
        assert((list == ForwardList{1, 2, 3, 4, 8}));
    }

    {
        ForwardList list = {1, 2, 3, 4, 5};
        list.pushBack(8);
        assert((list == ForwardList{1, 2, 3, 4, 5, 8}));
    }

    std::cout << "Passed" << std::endl;
}


void testPopFront() {
    std::cout << "test popFront(): ";

    {
        ForwardList list;
        list.popFront();
        assert((list.empty()));
    }

    {
        ForwardList list = {1};
        list.popFront();
        assert((list.empty()));
    }

    {
        ForwardList list = {1, 2};
        list.popFront();
        assert((list == ForwardList{2}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.popFront();
        assert((list == ForwardList{2, 3}));
    }

    {
        ForwardList list = {1, 2, 3, 4};
        list.popFront();
        assert((list == ForwardList{2, 3, 4}));
    }

    {
        ForwardList list = {1, 2, 3, 4, 5};
        list.popFront();
        assert((list == ForwardList{2, 3, 4, 5}));
    }

    std::cout << "Passed" << std::endl;
}


void testPopBack() {
    std::cout << "test popBack(): ";

        {
        ForwardList list;
        list.popBack();
        assert((list.empty()));
    }

    {
        ForwardList list = {1};
        list.popBack();
        assert((list.empty()));
    }

    {
        ForwardList list = {1, 2};
        list.popBack();
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.popBack();
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list = {1, 2, 3, 4};
        list.popBack();
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list = {1, 2, 3, 4, 5};
        list.popBack();
        assert((list == ForwardList{1, 2, 3, 4}));
    }

    std::cout << "Passed" << std::endl;
}
//
//void testRemove() {
//    std::cout << "test remove(): ";
//
//    // remove from the start of a three-element list 
//    ForwardList list1 {1, 2, 3};
//    list1.remove(1);
//    assert((list1 == ForwardList{2, 3}));
//
//    // remove from the mid of a three-element list 
//    ForwardList list2 {1, 2, 3};
//    list2.remove(2);
//    assert((list2 == ForwardList{1, 3}));
//
//    // remove from the end of a three-element list
//    ForwardList list3 {1, 2, 3};
//    list3.remove(3);
//    assert((list3 == ForwardList{1, 2}));
//
//    // remove non-existent value from a three-element list 
//    ForwardList list4 {12, 15, 95};
//    list4.remove(18);
//    assert((list4 == ForwardList{12, 15, 95}));
//
//    // remove from the start of a two-element list 
//    ForwardList list5 {6, 8};
//    list5.remove(6);
//    assert((list5 == ForwardList{8}));
//
//    // remove from the end of a two-element list 
//    ForwardList list6 {6, 8};
//    list6.remove(8);
//    assert((list6 == ForwardList{6}));
//
//    // remove non-existent value from a two-element list 
//    ForwardList list7 {6, 8};
//    list7.remove(44);
//    assert((list7 == ForwardList{6, 8}));
//
//    // remove existing value from a one-element list 
//    ForwardList list8 {6};
//    list8.remove(6);
//    assert((list8.empty()));
//
//    // remove non-existent value from a one-element list 
//    ForwardList list9 {6};
//    list9.remove(1);
//    assert((list9 == ForwardList{6}));
//
//    // remove from an empty list
//    ForwardList list10;
//    list10.remove(4);
//    assert((list10.empty()));
//
//    // remove a repeating value
//    ForwardList list11 {5, 18, 14, -4, 18};
//    list11.remove(18);
//    assert((list11 == ForwardList{5, 14, -4}));
//
//    std::cout << "Passed" << std::endl;
//}
//
//void testEraseAfter() {
//    std::cout << "test EraseAfter(): ";
//
//    // erease after beforeBegin()
//    ForwardList list {2, 4, 6};
//    auto it = list.beforeBegin();
//    list.eraseAfter(it);
//    assert((list == ForwardList{4, 6}));
//    
//    // erease after begin()
//    ForwardList list2 {2, 4, 6};
//    auto it2 = list2.begin();
//    list2.eraseAfter(it2);
//    assert((list2 == ForwardList{2, 6}));
//
//    // erease after end()
//    ForwardList list3 {2, 4, 6};
//    auto it3 = list3.end();
//    list3.eraseAfter(it3);
//    assert((list3 == ForwardList{2, 4, 6}));
//
//    // erase the last element
//    ForwardList list4 {3, 6, 9, 12};
//    auto it4 = list4.begin();
//    ++(++it4); 
//    list4.eraseAfter(it4);
//    assert((list4 == ForwardList{3, 6, 9}));
//
//    // erase the mid element
//    ForwardList list5 {10, 12, 16, -5, 18};
//    auto it5 = list5.begin();
//    ++it5;
//    list5.eraseAfter(it5);
//    assert((list5 == ForwardList{10, 12, -5, 18}));
//
//    // erasing empty list with various iterators
//
//    ForwardList list6;
//    list6.eraseAfter(list6.beforeBegin());
//    assert(list6 == ForwardList());
//
//    ForwardList list7;
//    list7.eraseAfter(list7.begin());
//    assert(list7 == ForwardList());
//
//    ForwardList list8;
//    list8.eraseAfter(list8.end());
//    assert(list8 == ForwardList());
//
//    // ranged erase with the same iterator
//    ForwardList list9{5, 50, 565};
//    auto start9 = list9.beforeBegin();
//    list9.eraseAfter(start9, start9);
//    assert((list9 == ForwardList{5, 50, 565}));
//
//    // ranged erase with neighbours
//    ForwardList list10{15, 450, 55};
//    auto start10 = list10.beforeBegin();
//    auto end10 = list10.begin();
//    list10.eraseAfter(start10, end10);
//    assert((list10 == ForwardList{15, 450, 55}));
//
//    // standard ranged erase A
//    ForwardList list11{7, 540, 135, 443};
//    auto start11 = list11.beforeBegin();
//    auto end11 = ++(list11.begin());
//    list11.eraseAfter(start11, end11);
//    assert((list11 == ForwardList{540, 135, 443}));
//
//    // standard ranged erase B
//    ForwardList list12{113, 24, 65, 89};
//    auto start12 = ++(list12.begin());
//    auto end12 = list12.end();
//    list12.eraseAfter(start12, end12);
//    assert((list12 == ForwardList{113, 24}));
//
//    // standard ranged erase C
//    ForwardList list13{100, 244, 415, 98};
//    auto start13 = list13.beforeBegin();
//    auto end13 = list13.end();
//    list13.eraseAfter(start13, end13);
//    assert(list13.empty());
//
//    std::cout << "Passed" << std::endl;
//}
//
//void testInsertAfter() {
//
//}


int main() {
    testClear();
    testPushFront();
    testPushBack();
    testPopFront();
    testPopBack();
    //testRemove();
    //testEraseAfter();
    return 0;
}