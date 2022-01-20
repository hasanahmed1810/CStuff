

#ifndef LEARNINGC__9_LINKEDLISTSTACK_H
#define LEARNINGC__9_LINKEDLISTSTACK_H

#include <iostream>
using namespace std;

class LinkedListStack {
public:
    struct node{
        int value;
        node *next;
    };

    LinkedListStack();

    void push(int number);

    int pop();

    bool isEmpty();

    int peek();

    void display();

private:
    int size;
    node *top;
};


#endif //LEARNINGC__9_LINKEDLISTSTACK_H
