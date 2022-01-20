
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

int DoublyLinkedList::isEmpty() {
    return head == nullptr;
}

void DoublyLinkedList::addToTail(int number) {
    if (tail != nullptr){ // if list is not empty
        tail = new Node(number, nullptr, tail);
        tail->prev->next = tail;
    }
    else{
        head = tail = new Node(number);
    }
}

int DoublyLinkedList::deleteFromTail() {
    int number = tail->value;
    if (head == tail){ //if only one node in the list
        delete head;
        head = tail = nullptr;
    }
    else{
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return number;
}

void DoublyLinkedList::display() {
    Node *nodePtr = head;

    while(nodePtr){
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
