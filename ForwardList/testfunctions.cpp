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

void testRemove() {
    std::cout << "test remove(): ";

    // empty
    {
        ForwardList list {};
        list.remove(1);
        assert(list.empty());
    }

    // one element
    {
        ForwardList list {1};
        list.remove(1);
        assert(list.empty());
    }

    {
        ForwardList list {1};
        list.remove(0);
        assert(list == ForwardList{1});
    }

    // two elements
    {
        ForwardList list {1, 2};
        list.remove(1);
        assert(list == ForwardList{2});
    }

    {
        ForwardList list {1, 2};
        list.remove(2);
        assert(list == ForwardList{1});
    }

    {
        ForwardList list {1, 2};
        list.remove(3);
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list {2, 2};
        list.remove(2);
        assert(list.empty());
    }

    // three elements 
    {
        ForwardList list {1, 2, 3};
        list.remove(3);
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list {1, 2, 3};
        list.remove(2);
        assert((list == ForwardList{1, 3}));
    }

    {
        ForwardList list {1, 2, 3};
        list.remove(1);
        assert((list == ForwardList{2, 3}));
    }

    {
        ForwardList list {1, 1, 2};
        list.remove(1);
        assert((list == ForwardList{2}));
    }

    {
        ForwardList list {1, 2, 1};
        list.remove(1);
        assert((list == ForwardList{2}));
    }

    {
        ForwardList list {1, 1, 2};
        list.remove(1);
        assert((list == ForwardList{2}));
    }

    {
        ForwardList list {1, 1, 1};
        list.remove(1);
        assert(list.empty());
    }

    // four elements
    {
        ForwardList list {1, 2, 3, 4};
        list.remove(1);
        assert((list == ForwardList{2, 3, 4}));
    }

    {
        ForwardList list {1, 2, 3, 4};
        list.remove(2);
        assert((list == ForwardList{1, 3, 4}));
    }

    {
        ForwardList list {1, 2, 3, 4};
        list.remove(3);
        assert((list == ForwardList{1, 2, 4}));
    }

    {
        ForwardList list {1, 2, 3, 4};
        list.remove(4);
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list {1, 2, 3, 4};
        list.remove(5);
        assert((list == ForwardList{1, 2, 3, 4}));
    }

    {
        ForwardList list {1, 2, 1, 4};
        list.remove(1);
        assert((list == ForwardList{2, 4}));
    }

    std::cout << "Passed" << std::endl;
}

void testEraseAfter() {
    std::cout << "test eraseAfter(): ";

    // empty
    {
        ForwardList list;
        list.eraseAfter(list.beforeBegin());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.begin());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.end());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.beforeBegin(), list.beforeBegin());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.beforeBegin(), list.begin());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.beforeBegin(), list.end());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.begin(), list.begin());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.begin(), list.end());
        assert(list.empty());
    }

    {
        ForwardList list;
        list.eraseAfter(list.end(), list.end());
        assert(list.empty());
    }

    // one element
    {
        ForwardList list = {1};
        list.eraseAfter(list.beforeBegin());
        assert(list.empty());
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.begin());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.end());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.beforeBegin(), list.beforeBegin());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.beforeBegin(), list.begin());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.beforeBegin(), list.end());
        assert(list.empty());
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.begin(), list.begin());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.begin(), list.end());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1};
        list.eraseAfter(list.end(), list.end());
        assert((list == ForwardList{1}));
    }

    // two elements
    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.beforeBegin());
        assert((list == ForwardList{2}));
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.begin());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.end());
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.beforeBegin(), list.beforeBegin());
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.beforeBegin(), list.begin());
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.beforeBegin(), list.end());
        assert(list.empty());
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.begin(), list.begin());
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.begin(), list.end());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1, 2};
        list.eraseAfter(list.end(), list.end());
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list = {1, 2};
        auto it = list.begin();
        ++it;
        list.eraseAfter(it, list.end());
        assert((list == ForwardList{1, 2}));
    }

    // three elements
    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.beforeBegin());
        assert((list == ForwardList{2, 3}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.begin());
        assert((list == ForwardList{1, 3}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.end());
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.beforeBegin(), list.beforeBegin());
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.beforeBegin(), list.begin());
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.beforeBegin(), list.end());
        assert(list.empty());
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.begin(), list.begin());
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.begin(), list.end());
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list = {1, 2, 3};
        list.eraseAfter(list.end(), list.end());
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list = {1, 2, 3};
        auto it = list.begin();
        ++it;
        list.eraseAfter(it, list.end());
        assert((list == ForwardList{1, 2}));
    }

    // > 3 elements
    {
        ForwardList list = {1, 2, 3, 4, 5, 6, 7};
        auto it = list.begin();
        ++it; // 2
        auto it2 = list.begin();
        ++(++(++(++it2))); // 5
        list.eraseAfter(it, it2);
        assert((list == ForwardList{1, 2, 5, 6, 7}));
    }

    {
        ForwardList list = {1, 2, 3, 4, 5, 6, 7};
        auto it = list.begin();
        ++(++(++(++it))); // 5
        list.eraseAfter(it, list.end());
        assert((list == ForwardList{1, 2, 3, 4, 5}));
    }

    std::cout << "Passed" << std::endl;
}

void testInsertAfter() {
    std::cout << "test insertAfter(): ";

    // empty
    {
        ForwardList list;
        list.insertAfter(list.beforeBegin(), 1);
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list;
        list.insertAfter(list.beforeBegin(), {1, 2});
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list;
        list.insertAfter(list.begin(), 1);
        assert((list.empty()));
    }

    {
        ForwardList list;
        list.insertAfter(list.begin(), {1, 2});
        assert((list.empty()));
    }

    {
        ForwardList list;
        list.insertAfter(list.end(), 1);
        assert((list.empty()));
    }

    {
        ForwardList list;
        list.insertAfter(list.end(), {1, 2});
        assert((list.empty()));
    }

    // one element
    {
        ForwardList list{1};
        list.insertAfter(list.beforeBegin(), 2);
        assert((list == ForwardList{2, 1}));
    }

    {
        ForwardList list{1};
        list.insertAfter(list.beforeBegin(), {2, 3});
        assert((list == ForwardList{2, 3, 1}));
    }

    {
        ForwardList list{1};
        list.insertAfter(list.begin(), 2);
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list{1};
        list.insertAfter(list.begin(), {2, 3});
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list{1};
        list.insertAfter(list.end(), 2);
        assert((list == ForwardList{1}));
    }

    {
        ForwardList list{1};
        list.insertAfter(list.end(), {2, 3});
        assert((list == ForwardList{1}));
    }

    // two elements
    {
        ForwardList list{1, 2};
        list.insertAfter(list.beforeBegin(), 3);
        assert((list == ForwardList{3, 1, 2}));
    }

    {
        ForwardList list{1, 2};
        list.insertAfter(list.beforeBegin(), {3, 4});
        assert((list == ForwardList{3, 4, 1, 2}));
    }

    {
        ForwardList list{1, 2};
        list.insertAfter(list.begin(), 3);
        assert((list == ForwardList{1, 3, 2}));
    }

    {
        ForwardList list{1, 2};
        list.insertAfter(list.begin(), {3, 4});
        assert((list == ForwardList{1, 3, 4, 2}));
    }

    {
        ForwardList list{1, 2};
        list.insertAfter(list.end(), 2);
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list{1, 2};
        list.insertAfter(list.end(), {2, 3});
        assert((list == ForwardList{1, 2}));
    }

    {
        ForwardList list{1, 2};
        auto it = ++(list.begin());
        list.insertAfter(it, 3);
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list{1, 2};
        auto it = ++(list.begin());
        list.insertAfter(it, {3, 4});
        assert((list == ForwardList{1, 2, 3, 4}));
    }

    // three elements

    {
        ForwardList list{1, 2, 3};
        list.insertAfter(list.beforeBegin(), 4);
        assert((list == ForwardList{4, 1, 2, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        list.insertAfter(list.beforeBegin(), {4, 5});
        assert((list == ForwardList{4, 5, 1, 2, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        list.insertAfter(list.begin(), 4);
        assert((list == ForwardList{1, 4, 2, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        list.insertAfter(list.begin(), {4, 5});
        assert((list == ForwardList{1, 4, 5, 2, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        list.insertAfter(list.end(), 2);
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        list.insertAfter(list.end(), {2, 3});
        assert((list == ForwardList{1, 2, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        auto it = ++(list.begin());
        list.insertAfter(it, 4);
        assert((list == ForwardList{1, 2, 4, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        auto it = ++(list.begin());
        list.insertAfter(it, {4, 5});
        assert((list == ForwardList{1, 2, 4, 5, 3}));
    }

    {
        ForwardList list{1, 2, 3};
        auto it = ++(++(list.begin()));
        list.insertAfter(it, 4);
        assert((list == ForwardList{1, 2, 3, 4}));
    }

    {
        ForwardList list{1, 2, 3};
        auto it = ++(++(list.begin()));
        list.insertAfter(it, {4, 5});
        assert((list == ForwardList{1, 2, 3, 4, 5}));
    }

    // > 3 elements

    {
        ForwardList list{1, 2, 3, 4, 5, 6, 7 };
        auto it = ++(++(++(list.begin()))); // 4
        list.insertAfter(it, 8);
        assert((list == ForwardList{1, 2, 3, 4, 8, 5, 6, 7}));
    }

    {
        ForwardList list{1, 2, 3, 4, 5, 6, 7 };
        auto it = ++(++(++(list.begin()))); // 4
        list.insertAfter(it, {8, 9});
        assert((list == ForwardList{1, 2, 3, 4, 8, 9, 5, 6, 7}));
    }

    std::cout << "Passed" << std::endl;
}

void testSize() {
    std::cout << "test size(): ";

    {
        ForwardList list;
        assert(list.size() == 0);
    }

    {
        ForwardList list{5};
        assert(list.size() == 1);
    }

    {
        ForwardList list{5, 10};
        assert(list.size() == 2);
    }

    {
        ForwardList list{5, 10, 15};
        assert(list.size() == 3);
    }

    {
        ForwardList list{5, 10, 15, 20};
        assert(list.size() == 4);
    }

    std::cout << "Passed" << std::endl;
}

void testEmpty() {
    std::cout << "test empty(): ";

    {
        ForwardList list;
        assert(list.empty());
    }

    {
        ForwardList list{5};
        assert(!list.empty());
    }

    {
        ForwardList list{5, 10};
        assert(!list.empty());
    }

    {
        ForwardList list{5, 10, 15};
        assert(!list.empty());
    }

    {
        ForwardList list{5, 10, 15, 20};
        assert(!list.empty());
    }

    std::cout << "Passed" << std::endl;
}

void testEquality() {
    std::cout << "test ==: ";

    {
        ForwardList list;
        assert(list == ForwardList());
    }

    {
        ForwardList list;
        assert(!(list == ForwardList{1}));
    }

    {
        ForwardList list{5};
        assert(list == ForwardList{5});
    }

    {
        ForwardList list{5};
        assert(!(list == ForwardList {8}));
    }

    {
        ForwardList list{5, 10};
        assert((list == ForwardList{5, 10}));
    }

    {
        ForwardList list{5, 10};
        assert(!(list == ForwardList{5, 6}));
    }

    {
        ForwardList list{5, 10, 15};
        assert((list == ForwardList{5, 10, 15}));
    }

    {
        ForwardList list{5, 10, 15};
        assert(!(list == ForwardList{5, 3, 15}));
    }

    {
        ForwardList list{5, 10, 15, 20};
        assert((list == ForwardList{5, 10, 15, 20}));
    }

    {
        ForwardList list{5, 10, 15, 20};
        assert(!(list == ForwardList{5, 10, 15, 21}));
    }

    std::cout << "Passed" << std::endl;
}

void testInequality() {
    std::cout << "test !=: ";

    {
        ForwardList list;
        assert(!(list != ForwardList()));
    }

    {
        ForwardList list;
        assert((list != ForwardList{1}));
    }

    {
        ForwardList list{5};
        assert(!(list != ForwardList{5}));
    }

    {
        ForwardList list{5};
        assert((list != ForwardList {8}));
    }

    {
        ForwardList list{5, 10};
        assert(!(list != ForwardList{5, 10}));
    }

    {
        ForwardList list{5, 10};
        assert((list != ForwardList{5, 6}));
    }

    {
        ForwardList list{5, 10, 15};
        assert(!(list != ForwardList{5, 10, 15}));
    }

    {
        ForwardList list{5, 10, 15};
        assert((list != ForwardList{5, 3, 15}));
    }

    {
        ForwardList list{5, 10, 15, 20};
        assert(!(list != ForwardList{5, 10, 15, 20}));
    }

    {
        ForwardList list{5, 10, 15, 20};
        assert((list != ForwardList{5, 10, 15, 21}));
    }

    std::cout << "Passed" << std::endl;
}

void testAccess() {
    std::cout << "test access API: ";

    {
        ForwardList list;
        auto it = list.beforeBegin();
        ++it;
        assert(it == list.end());
    }

    {
        ForwardList list;
        assert(list.begin() == list.end());
    }

    {
        ForwardList list{1};
        auto it = list.beforeBegin();
        ++it;
        assert(*it == 1);
    }

    {
        ForwardList list{1};
        auto it = list.begin();
        assert(*it == 1);
    }

    {
        ForwardList list{1};
        auto it = ++(list.begin());
        assert(it == list.end());
    }

    {
        ForwardList list{1, 2};
        auto it = list.beforeBegin();
        ++it;
        assert(*it == 1);
        ++it;
        assert(*it == 2);
    }

    {
        ForwardList list{1, 2};
        auto it = list.begin();
        assert(*it == 1);
        ++it;
        assert(*it == 2);
    }

    {
        ForwardList list{1, 2, 3};
        auto it = list.begin();
        *it = 5;
        ++it;
        *it = 10;
        ++it;
        *it = 15;
        assert((list == ForwardList{5, 10, 15}));
    }

    {
        ForwardList list{1};
        assert(list.front() == 1);
        assert(list.back() == 1);
    }

    {
        ForwardList list{1, 2};
        assert(list.front() == 1);
        assert(list.back() == 2);
    }

    {
        ForwardList list{1, 2, 3};
        assert(list.front() == 1);
        assert(list.back() == 3);
    }

    {
        ForwardList list{1, 2, 3, 4};
        assert(list.front() == 1);
        assert(list.back() == 4);
    }

    {
        ForwardList list{1, 2, 3, 4};
        int& f = list.front();
        f = 80;
        int& b = list.back();
        b = 90;
        assert((list == ForwardList{80, 2, 3, 90}));
    }

    std::cout << "Passed" << std::endl;
}


// testing just one of the reverse funtions
void testReverse() {
    std::cout << "test reverse(): ";

    {
        ForwardList list;
        list.reverse();
        assert(list.empty());
    }

    {
        ForwardList list{2};
        list.reverse();
        assert(list == ForwardList{2});
    }

    {
        ForwardList list{2, 4};
        list.reverse();
        assert((list == ForwardList{4, 2}));
    }

    {
        ForwardList list{2, 4, 6};
        list.reverse();
        assert((list == ForwardList{6, 4, 2}));
    }

    {
        ForwardList list{2, 4, 6, 8};
        list.reverse();
        assert((list == ForwardList{8, 6, 4, 2}));
    }

    {
        ForwardList list{2, 4, 6, 8};
        list.reverse();
        list.reverse();
        assert((list == ForwardList{2, 4, 6, 8}));
    }

    std::cout << "Passed" << std::endl;
}

void testSort() {
    std::cout << "test sort(): ";

    {
        ForwardList list;
        list.sort();
        assert(list.empty());
    }

    {
        ForwardList list{2};
        list.sort();
        assert(list == ForwardList{2});
    }

    {
        ForwardList list{2, 4};
        list.sort();
        assert((list == ForwardList{2, 4}));
    }

    {
        ForwardList list{4, 2};
        list.sort();
        assert((list == ForwardList{2, 4}));
    }

    {
        ForwardList list{2, 4, 6};
        list.sort();
        assert((list == ForwardList{2, 4, 6}));
    }

    {
        ForwardList list{2, 6, 4};
        list.sort();
        assert((list == ForwardList{2, 4, 6}));
    }

    {
        ForwardList list{4, 2, 6};
        list.sort();
        assert((list == ForwardList{2, 4, 6}));
    }

    {
        ForwardList list{4, 6, 2};
        list.sort();
        assert((list == ForwardList{2, 4, 6}));
    }

    {
        ForwardList list{6, 2, 4};
        list.sort();
        assert((list == ForwardList{2, 4, 6}));
    }

    {
        ForwardList list{6, 4, 2};
        list.sort();
        assert((list == ForwardList{2, 4, 6}));
    }

    {
        ForwardList list{2, 3, 3};
        list.sort();
        assert((list == ForwardList{2, 3, 3}));
    }

    {
        ForwardList list{3, 2, 3};
        list.sort();
        assert((list == ForwardList{2, 3, 3}));
    }

    {
        ForwardList list{3, 3, 2};
        list.sort();
        assert((list == ForwardList{2, 3, 3}));
    }

    {
        ForwardList list{5, 1, 0, 8, -199};
        list.sort();
        assert((list == ForwardList{-199, 0, 1, 5, 8}));
    }

    {
        ForwardList list{5, 1, 0, 8, -199};
        list.sort();
        assert((list == ForwardList{-199, 0, 1, 5, 8}));
    }

    {
        ForwardList list{5, 1, 0, 8, -199};
        list.sort([](int x, int y){ return x > y;});
        assert((list == ForwardList{8, 5, 1, 0, -199}));
    }

    std::cout << "Passed" << std::endl;
}

void testMerge() {
    std::cout << "test merge(): ";

    {
        ForwardList list1;
        ForwardList list2;
        list1.merge(list2);
        assert(list1.empty());
        assert(list2.empty());
    }

    {
        ForwardList list1{5};
        ForwardList list2;
        list1.merge(list2);
        assert((list1 == ForwardList{5}));
        assert((list2.empty()));
    }

    {
        ForwardList list1;
        ForwardList list2{3};
        list1.merge(list2);
        assert((list1 == ForwardList{3}));
        assert((list2.empty()));
    }

    {
        ForwardList list1{5};
        ForwardList list2{3};
        list1.merge(list2);
        assert((list1 == ForwardList{3, 5}));
        assert((list2.empty()));
    }

    {
        ForwardList list1{3};
        ForwardList list2{5};
        list1.merge(list2);
        assert((list1 == ForwardList{3, 5}));
        assert((list2.empty()));
    }

    {
        ForwardList list1{-5, 5, 15};
        ForwardList list2{1, 2, 6};
        list1.merge(list2);
        assert((list1 == ForwardList{-5, 1, 2, 5, 6, 15}));
        assert((list2.empty()));
    }

    {
        ForwardList list1{1, 10, 100, 425};
        ForwardList list2{-500, 350, 600, 1000, 90000};
        list1.merge(list2);
        assert((list1 == ForwardList{-500, 1, 10, 100, 350, 425, 600, 1000, 90000}));
        assert((list2.empty()));
    }

    std::cout << "Passed" << std::endl;
}

void testCtorsCopyAndMove() {
    std::cout << "test ctors, copy and move: ";

    // default ctor
    {
        ForwardList list;
        assert(list.empty());
    }

    //  initializer list ctor
    {
        ForwardList list{1, 2, 3, 4};
        int i = 1;
        for(auto e : list) {
            assert(e == i);
            ++i;
        }
    }

    // copy ctor
    {
        ForwardList list1 {1, 2, 3};
        ForwardList list2 = list1;
        assert((list1 == ForwardList{1, 2, 3}));
        assert((list2 == ForwardList{1, 2, 3}));
        // verify that they don't share memory
        *list1.begin() = 8;
        assert(list1.front() == 8 && list2.front() == 1);
    }

    // copy assignment
    {
        ForwardList list1;
        ForwardList list2 {1, 2, 3};
        list1 = list2;
        assert((list1 == ForwardList{1, 2, 3}));
        assert((list2 == ForwardList{1, 2, 3}));
        // verify that they don't share memory
        list1.clear();
        assert(list1.empty() && list2.size() == 3);
    }

    // move ctor
    {
        ForwardList list{4, 3, 2};
        ForwardList list2 = std::move(list);
        assert(list.empty());
        assert((list2 == ForwardList{4, 3, 2}));
    }

    // move assignment
    {
        ForwardList list1 {1, 2, 3};
        ForwardList list2 {4, 5, 6};
        list1 = std::move(list2);
        assert((list1 == ForwardList{4, 5, 6}));
        assert(list2.empty());
    }

    // self-assignment
    {
        ForwardList list {5};
        list = list;
        assert(list == ForwardList{5});
        list = std::move(list);
        assert(list == ForwardList{5});
    }

    std::cout << "Passed" << std::endl;
}

void runTests() {
    testClear();
    testPushFront();
    testPushBack();
    testPopFront();
    testPopBack();
    testRemove();
    testEraseAfter();
    testInsertAfter();
    testSize();
    testEmpty();
    testEquality();
    testInequality();
    testAccess();
    testReverse();
    testSort();
    testMerge();
    testCtorsCopyAndMove();
}