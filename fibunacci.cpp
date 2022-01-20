#include <iostream>
#include <ctime>

using namespace std;

void fibonacciUsingRecursion(int numberOfTerms) {
    static long double firstTerm = 0;
    static long double secondTerm = 1;
    static long double nextTerm;
    if (firstTerm == 0 && secondTerm == 1){
        cout << firstTerm << " " << secondTerm << " ";
    }
    if (numberOfTerms > 1) {
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
        cout << nextTerm << " ";
        fibonacciUsingRecursion(numberOfTerms - 1);
    }
    else{
        cout << endl;
    }
}

void fibonacciUsingLoops(int numberOfTerms) {
    long double firstTerm = 0;
    long double secondTerm = 1;
    long double nextTerm;
    for (int i = 0; i <= numberOfTerms; ++i) {
        if (i == 0) {
            cout << firstTerm << " ";
            continue;
        }
        if (i == 1) {
            cout << secondTerm << " ";
            continue;
        }
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
        cout << nextTerm << " ";
    }
    cout << endl;
}

int main() {
    int numberOfTerms;
    cout << "Enter the number of terms:";
    cin >> numberOfTerms;
    cout << "Fibonacci series using loops" << endl;
    clock_t startTimeLoops = clock();
    fibonacciUsingLoops(numberOfTerms);
    cout << "Time taken in milliseconds: " << clock() - startTimeLoops << "ms" << endl;
    cout << endl;
    cout << "Fibonacci series using recursion" << endl;
    clock_t startTimeRecursion = clock();
    fibonacciUsingRecursion(numberOfTerms);
    cout << "Time taken in milliseconds: " << clock() - startTimeRecursion << "ms" << endl;
    return 0;
}
