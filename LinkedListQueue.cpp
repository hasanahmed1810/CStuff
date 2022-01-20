
#include "LinkedListQueue.h"

LinkedListQueue::LinkedListQueue() {
    front = nullptr;
    rear = nullptr;
}

void LinkedListQueue::enQueue(int number) {
    Node *temp = new Node;
    temp->value = number;

    if (rear == nullptr){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

void LinkedListQueue::deQueue() {
    if (front == nullptr){
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    front = front->next;

    if (front == nullptr){
        rear = nullptr;
    }

    delete temp;
}

void LinkedListQueue::display() {
    if (front == nullptr){
        cout << "Queue is empty" << endl;
    }
    else{
        Node *nodePtr = front;
        while (nodePtr){
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }
}

void LinkedListQueue::firstElement() {
    if (front == nullptr){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << front->value << endl;
    }
}

void LinkedListQueue::clear() {
    while (front){
        deQueue();
    }
}
