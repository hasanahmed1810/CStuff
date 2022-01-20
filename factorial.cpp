#include <iostream>
#include <ctime>

using namespace std;

void factorialUsingLoops(int number) {
    long double factorial = 1;
    for (int i = 1; i <= number; i++) {
        factorial = factorial * i;
    }
    cout << "Factorial of " << number << " is: " << factorial << endl;
}

long double factorialUsingRecursion(int number){
    static const int theNumber = number;
    if(number > 1){
        return number * factorialUsingRecursion(number - 1);
    }
    else{
        cout << "Factorial of " << theNumber << " is: ";
        return 1;
    }
}

int main() {
    int number;
    cout << "Enter any number:";
    cin >> number;
    cout << "Factorial using loops" << endl;
    clock_t startTimeLoops = clock();
    factorialUsingLoops(number);
    cout << "Time taken in milliseconds: " << clock() - startTimeLoops << "ms" << endl;
    cout << endl;
    cout << "Factorial using recursion" << endl;
    clock_t startTimeRecursion = clock();
    cout << factorialUsingRecursion(number) << endl;
    cout << "Time taken in milliseconds: " << clock() - startTimeRecursion << "ms" << endl;
}