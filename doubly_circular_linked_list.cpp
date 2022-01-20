#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

/*
 * Class Declaration
 */
class DoubleCircularList {
public:
    int counter = 0;

    /*
     * Node Declaration
     */
    struct node {
        int info;
        struct node *next;
        struct node *prev;
    } *start, *last;

    DoubleCircularList() {
        start = nullptr;
        last = nullptr;
    }

    /*
     *CREATE NODE AND ALLOCATE MEMORY DYNAMICALLY
     */
    node *createNode(int value) {
        counter++;
        node *temp = new node;
        temp->info = value;
        temp->next = nullptr;
        temp->prev = nullptr;
        return temp;
    }

    /*
     *INSERTS ELEMENT AT BEGINNING
     */
    void insertAtStart() {
        int value;
        cout << endl << "Enter the element to be inserted: ";
        cin >> value;
        node *temp = createNode(value);
        if (start == last && start == nullptr) {
            cout << "Element inserted in empty list" << endl;
            start = last = temp;
            start->next = last->next = nullptr;
            start->prev = last->prev = nullptr;
        } else {
            temp->next = start;
            start->prev = temp;
            start = temp;
            start->prev = last;
            last->next = start;
            cout << "Element inserted" << endl;
        }
    }

    /*
     *INSERTS ELEMNET AT LAST
     */
    void insertLast() {
        int value;
        cout << endl << "Enter the element to be inserted: ";
        cin >> value;
        node *temp;
        temp = createNode(value);
        if (start == last && start == nullptr) {
            cout << "Element inserted in empty list" << endl;
            start = last = temp;
            start->next = last->next = nullptr;
            start->prev = last->prev = nullptr;
        } else {
            last->next = temp;
            temp->prev = last;
            last = temp;
            start->prev = last;
            last->next = start;
        }
    }

    /*
     *INSERTS ELEMENT AT POSITION
     */
    void insertAtPos() {
        int value, pos;
        cout << endl << "Enter the element to be inserted: ";
        cin >> value;
        cout << endl << "Enter the position of element inserted: ";
        cin >> pos;
        node *temp, *_start, *ptr;
        temp = createNode(value);
        if (start == last && start == nullptr) {
            if (pos == 1) {
                start = last = temp;
                start->next = last->next = nullptr;
                start->prev = last->prev = nullptr;
            } else {
                cout << "Position out of range" << endl;
                counter--;
                return;
            }
        } else {
            if (counter < pos) {
                cout << "Position out of range" << endl;
                counter--;
                return;
            }
            _start = start;
            for (int i = 1; i <= counter; i++) {
                ptr = _start;
                _start = _start->next;
                if (i == pos - 1) {
                    ptr->next = temp;
                    temp->prev = ptr;
                    temp->next = _start;
                    _start->prev = temp;
                    cout << "Element inserted" << endl;
                    break;
                }
            }
        }
    }

    /*
     * Delete Node at Particular Position
     */
    void deleteAtPos() {
        int pos;
        node *ptr, *_start;
        if (start == last && start == nullptr) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        cout << endl << "Enter the postion of element to be deleted: ";
        cin >> pos;
        if (counter < pos) {
            cout << "Position out of range" << endl;
            return;
        }
        _start = start;
        if (pos == 1) {
            counter--;
            last->next = _start->next;
            _start->next->prev = last;
            start = _start->next;
            free(_start);
            cout << "Element Deleted" << endl;
            return;
        }
        for (int i = 0; i < pos - 1; i++) {
            _start = _start->next;
            ptr = _start->prev;
        }
        ptr->next = _start->next;
        _start->next->prev = ptr;
        if (pos == counter) {
            last = ptr;
        }
        counter--;
        free(_start);
        cout << "Element Deleted" << endl;
    }

    /*
     * Display Elements of the List
     */
    void display() {
        node *_start;
        if (start == last && start == nullptr) {
            cout << "The List is empty, nothing to display" << endl;
            return;
        }
        _start = start;
        for (int i = 0; i < counter - 1; i++) {
            cout << _start->info << "<->";
            _start = _start->next;
        }
        cout << _start->info << endl;
    }
};

/*
 * Main: Contains Menu
 */
int main() {
    int userChoice;
    DoubleCircularList cdl;
    while (true) {
        cout << "\n-------------------------------" << endl;
        cout << "Operations on Doubly Circular linked list" << endl;
        cout << "\n-------------------------------" << endl;
        cout << "1.Insert at Beginning" << endl;
        cout << "2.Insert at Last" << endl;
        cout << "3.Insert at Specific Position" << endl;
        cout << "4.Delete at Specific Position" << endl;
        cout << "5.Display List" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> userChoice;
        switch (userChoice) {
            case 1:
                cdl.insertAtStart();
                break;
            case 2:
                cdl.insertLast();
                break;
            case 3:
                cdl.insertAtPos();
                break;
            case 4:
                cdl.deleteAtPos();
                break;
            case 5:
                cdl.display();
                break;
            case 6:
                exit(1);
            default:
                cout << "Wrong choice" << endl;
        }
    }
    return 0;
}