
#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() {
    this->tail = nullptr;
}

void CircularLinkedList::addToTail(int value) {
    if (tail == nullptr){
        tail = new node;
        tail->data = value;
        tail->next = tail;
    }
    else{
        node *newNode = new node;
        newNode->data = value;
        newNode->next = tail->next;
        tail->next = newNode;
        tail = tail->next;
    }
}

void CircularLinkedList::display() {
    node *nodePtr = tail->next;
    if (nodePtr != nullptr){
        while (nodePtr != tail){
            cout << nodePtr->data << " ";
            nodePtr = nodePtr->next;
        }
        cout << nodePtr->data << endl;
    }
}
