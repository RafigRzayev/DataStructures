#pragma once

template<typename T>
class LinkedList {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
    };
public:
    class Iterator {

    };
private:

    Node* head = nullptr;
    Node* tail = nullptr;
};