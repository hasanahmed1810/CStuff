
#ifndef LEARNINGC__8_DOUBLYLINKEDLIST_H
#define LEARNINGC__8_DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

class DoublyLinkedList {
public:
    struct Node{
        int value;
        Node *next;
        Node *prev;
        Node(){
            next = nullptr;
            prev = nullptr;
        }
        Node(int _value, Node *_next = nullptr, Node *_prev = nullptr){
            value = _value;
            next = _next;
            prev = _prev;
        }
    };

    DoublyLinkedList();

    int isEmpty();

    void addToTail(int number);

    int deleteFromTail();

    void display();

private:
    Node *head;
    Node *tail;
};

#endif //LEARNINGC__8_DOUBLYLINKEDLIST_H
