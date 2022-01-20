#include <iostream>
using namespace std;

class LinkedList {
private:
// Declare a structure for the list
    struct Node {
        int value;
        struct Node *next;
    };

    Node *head; // List head pointer

    int counter(){
        int counter = 0;
        Node *nodePtr = head;
        while (nodePtr){
            counter++;
            nodePtr = nodePtr->next;
        }
        return counter;
    }

public:
    LinkedList() { // Constructor
        head = nullptr;
    }

    void insertAtHead(int number){
        Node *newNode = new Node;
        newNode->value = number;
        if (head == nullptr){
            newNode->next = nullptr;
        }
        else{
            newNode->next=head;
        }
        head = newNode;
    }

    void insertAtLocation(int location,int number){
        if (location >= 1 && location <= counter()){
            Node *nodePtr = nullptr;
            Node *newNode = new Node;
            newNode->value = number;
            if (!head){
                cout << "list is not initialized" << endl;
                return;
            }
            else if (location == 1){
                insertAtHead(number);
            }
            else{
                nodePtr = head;
                for (int i=2; i<location; i++){
                    nodePtr = nodePtr->next;
                }
                newNode->next = nodePtr->next;
                nodePtr->next = newNode;
            }
        }
        else{
            cout << "Enter a valid location" << endl;
        }
    }

    void deleteNode(int number){
        Node *nodePtr = nullptr;
        Node *previousNode = nullptr;

        if (!head){
            cout << "list is empty" << endl;
            return;
        }

        if (head->value == number){
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        }
        else{
            nodePtr = head;
            while (nodePtr != nullptr && nodePtr->value != number){
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            previousNode->next = nodePtr->next;
            delete nodePtr;
        }

        cout << number << " is deleted from the list" << endl;
    }

    void displayList(){
        Node *nodePtr = head;
        while (nodePtr){
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

    void countList(){
        cout << "Number of items in the list are " << counter() << endl;
    }
};


int main() {
    LinkedList linkedList;
    linkedList.insertAtHead(5);
    linkedList.insertAtHead(4);
    linkedList.insertAtHead(2);
    linkedList.insertAtHead(1);
    linkedList.displayList();
    linkedList.insertAtLocation(3,3);
    linkedList.displayList();
    linkedList.countList();
    linkedList.deleteNode(5);
    linkedList.displayList();
    linkedList.countList();
    return 0;
}
