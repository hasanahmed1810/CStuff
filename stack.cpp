#include <iostream>
using namespace std;


class Stack {
private:
    int top = -1;
    char stack[100];
public:
    bool isFull(){
        int stackSize = sizeof(stack)/sizeof(stack[0]);
        return top == stackSize - 1;
    }

    bool isEmpty(){
        return top < 0;
    }

    void push(char character){
        if (!isFull()){
            stack[++top] = character;
        }
    }

    char pop(){
        char characterDeleted;
        if (!isEmpty()){
            characterDeleted = stack[top];
            stack[top--] = NULL;
        }
        return characterDeleted;
    }

    char peek(){
        if (!isEmpty()){
            return stack[top];
        }
    }

    void clear(){
        while (!isEmpty()){
            pop();
        }
    }
};

void expressionChecker(string expression){
    int expressionSize = expression.size();
    int counter = 0;
    bool valid = true;
    Stack stack;
    while (counter < expressionSize){
        if (expression[counter] == '(' || expression[counter] == '[' || expression[counter] == '{'){
            stack.push(expression[counter]);
        }
        if (expression[counter] == ')' || expression[counter] == ']' || expression[counter] == '}'){
            if (stack.isEmpty()){
                valid = false;
            } else{
                char deletedCharacter = stack.pop();
                if (deletedCharacter == '(' && expression[counter] != ')'){
                    valid = false;
                }
                if (deletedCharacter == '[' && expression[counter] != ']'){
                    valid = false;
                }
                if (deletedCharacter == '{' && expression[counter] != '}'){
                    valid = false;
                }
            }
        }
        counter++;
    }
    if (valid){
        cout << "Valid Expression" << endl;
    } else{
        cout << "Invalid Expression" << endl;
    }
}

int main(){
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    cout << endl;
    expressionChecker(expression);
    return 0;
}

