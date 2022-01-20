

#include "LinkedListStack.h"

LinkedListStack::LinkedListStack() {
    size = 0;
    top = nullptr;
}

void LinkedListStack::push(int number) {
    node *newNode = new node;
    newNode->value = number;
    if (top == nullptr){
        newNode->next = nullptr;
    }
    else{
        newNode->next=top;
    }
    top = newNode;
    size++;
}

int LinkedListStack::pop() {
    int deletedNumber;
    if (isEmpty()){
        return -1;
    }
    else{
        node *temp = top;
        top = top->next;
        deletedNumber = temp->value;
        delete temp;
        size--;
        return deletedNumber;
    }
}

bool LinkedListStack::isEmpty() {
    return size == 0;
}

int LinkedListStack::peek() {
    return top->value;
}

void LinkedListStack::display() {
    node *nodePtr = top;
    while (nodePtr){
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}


