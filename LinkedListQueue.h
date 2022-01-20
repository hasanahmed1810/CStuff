
#ifndef LEARNINGC__11_LINKEDLISTQUEUE_H
#define LEARNINGC__11_LINKEDLISTQUEUE_H

#include <iostream>
using namespace std;

class LinkedListQueue {
public:
    struct Node{
        int value;
        Node *next = nullptr;
    };

    LinkedListQueue();

    void enQueue(int number);

    void deQueue();

    void display();

    void firstElement();

    void clear();

private:
    Node *front;
    Node *rear;
};


#endif //LEARNINGC__11_LINKEDLISTQUEUE_H