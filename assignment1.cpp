#include <iostream>
#include <vector>
using namespace std;

class RegularStack {
public:
    struct node{
        int value;
        node *next;
    };

    RegularStack(){
        size = 0;
        top = nullptr;
    }

    void push(int number){
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

    void display(){
        node *nodePtr = top;
        while (nodePtr){
            cout << nodePtr->value;
            nodePtr = nodePtr->next;
        }
    }

    void pop() {
        if (size == 0){
            return;
        }
        else{
            node *temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    }

    void clear(){
        while (top){
            pop();
        }
    }


private:
    int size;
    node *top;
};

class DecoderStack {
public:
    struct node{
        char character;
        int position;
        node *next;
    };

    DecoderStack(){
        size = 1;
        top = nullptr;
    }

    void push(char character){
        if (character == 'S' || character == 'G'){
            node *newNode = new node;
            newNode->character = character;
            newNode->position = size;
            if (top == nullptr){
                newNode->next = nullptr;
            }
            else{
                newNode->next=top;
            }
            top = newNode;
            size++;
        }
        else{
            cout << "Invalid Input" << endl;
        }
    }

    void reverseStack(){
        node *newTop = nullptr;
        node *tmpNext = nullptr;
        while (top){
            tmpNext = top->next;
            top->next = newTop;
            newTop = top;
            top = tmpNext;
        }
        top = newTop;
    }

    void decodeSequence(){
        RegularStack regularStack;
        this->reverseStack();
        node *nodePtr = top;
        while (nodePtr->next){
            if (nodePtr->character == 'S' ){
                cout << nodePtr->position;
                regularStack.display();
                regularStack.clear();
            } else{
                regularStack.push(nodePtr->position);
            }
            nodePtr = nodePtr->next;
        }
        cout << nodePtr->position;
        regularStack.display();
        cout << endl;
    }

private:
    int size;
    node *top;
};

int main() {
    DecoderStack stack1;
    stack1.push('S');
    stack1.push('S');
    stack1.push('G');
    stack1.push('G');
    stack1.push('S');
    stack1.push('G');
    stack1.push('S');
    stack1.push('G');
    stack1.decodeSequence();
    DecoderStack stack2;
    stack2.push('S');
    stack2.push('G');
    stack2.push('S');
    stack2.push('G');
    stack2.push('S');
    stack2.push('S');
    stack2.decodeSequence();
    DecoderStack stack3;
    stack3.push('G');
    stack3.push('G');
    stack3.push('G');
    stack3.push('G');
    stack3.decodeSequence();
    DecoderStack stack4;
    stack4.push('S');
    stack4.push('S');
    stack4.push('S');
    stack4.push('S');
    stack4.decodeSequence();
    return 0;
}