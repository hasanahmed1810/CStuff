
#ifndef LEARNINGC__8_CIRCULARLINKEDLIST_H
#define LEARNINGC__8_CIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

class CircularLinkedList {
public:
    struct node{
        int data;
        node *next;
    };

    CircularLinkedList();

    void addToTail(int value);

    void display();
private:
    node* tail;
};


#endif //LEARNINGC__8_CIRCULARLINKEDLIST_H
