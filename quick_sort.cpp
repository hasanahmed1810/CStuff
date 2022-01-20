#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i = (start - 1);

    for (int j = start; j < end; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;
    return (i + 1);
}


void quickSort(int array[], int start, int end) {
    if (start < end) {

        int pIndex = partition(array, start, end);

        quickSort(array, start, pIndex - 1);
        quickSort(array, pIndex + 1, end);
    }
}

void fillArrayWithRandomNumbers(int array[], int size){
    srand(time(nullptr));
    for(int i = 0; i < size; i++){
        array[i] = rand() % 100 + 1;
    }
}

void sortArrayInAscendingOrder(int array[], int size){
    sort(array, array + size);
}

void sortArrayInDescendingOrder(int array[], int size){
    sort(array, array + size, greater<>());
}

int main(){
    int *arrayInAscendingOrder1 = new int[100];
    int *arrayInAscendingOrder2 = new int[1000];
    int *arrayInAscendingOrder3 = new int[10000];
    int *arrayInAscendingOrder4 = new int[100000];
    int *arrayInAscendingOrder5 = new int[1000000];

    fillArrayWithRandomNumbers(arrayInAscendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInAscendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder4, 100000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder5, 1000000);

    sortArrayInAscendingOrder(arrayInAscendingOrder1, 100);
    sortArrayInAscendingOrder(arrayInAscendingOrder2, 1000);
    sortArrayInAscendingOrder(arrayInAscendingOrder3, 10000);
    sortArrayInAscendingOrder(arrayInAscendingOrder4, 100000);
    sortArrayInAscendingOrder(arrayInAscendingOrder5, 1000000);

    clock_t startTimeForAscending1 = clock();
    quickSort(arrayInAscendingOrder1, 0, 99);
    cout << "Time taken to sort arrayInAscendingOrder1 using quick sort: " << clock() - startTimeForAscending1 << "ms" << endl;
    clock_t startTimeForAscending2 = clock();
    quickSort(arrayInAscendingOrder2, 0, 999);
    cout << "Time taken to sort arrayInAscendingOrder2 using quick sort: " << clock() - startTimeForAscending2 << "ms" << endl;
    clock_t startTimeForAscending3 = clock();
    quickSort(arrayInAscendingOrder3, 0, 9999);
    cout << "Time taken to sort arrayInAscendingOrder3 using quick sort: " << clock() - startTimeForAscending3 << "ms" << endl;
    clock_t startTimeForAscending4 = clock();
    quickSort(arrayInAscendingOrder4, 0, 99999);
    cout << "Time taken to sort arrayInAscendingOrder4 using quick sort: " << clock() - startTimeForAscending4 << "ms" << endl;
    clock_t startTimeForAscending5 = clock();
    quickSort(arrayInAscendingOrder5, 0, 999999);
    cout << "Time taken to sort arrayInAscendingOrder5 using quick sort: " << clock() - startTimeForAscending5 << "ms" << endl;

    cout << endl;

    int *arrayInDescendingOrder1 = new int[100];
    int *arrayInDescendingOrder2 = new int[1000];
    int *arrayInDescendingOrder3 = new int[10000];
    int *arrayInDescendingOrder4 = new int[100000];
    int *arrayInDescendingOrder5 = new int[1000000];

    fillArrayWithRandomNumbers(arrayInDescendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInDescendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder4, 100000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder5, 1000000);

    sortArrayInDescendingOrder(arrayInDescendingOrder1, 100);
    sortArrayInDescendingOrder(arrayInDescendingOrder2, 1000);
    sortArrayInDescendingOrder(arrayInDescendingOrder3, 10000);
    sortArrayInDescendingOrder(arrayInDescendingOrder4, 100000);
    sortArrayInDescendingOrder(arrayInDescendingOrder5, 1000000);

    clock_t startTimeForDescending1 = clock();
    quickSort(arrayInDescendingOrder1, 0, 99);
    cout << "Time taken to sort arrayInDescendingOrder1 using quick sort: " << clock() - startTimeForDescending1 << "ms" << endl;
    clock_t startTimeForDescending2 = clock();
    quickSort(arrayInDescendingOrder2, 0, 999);
    cout << "Time taken to sort arrayInDescendingOrder2 using quick sort: " << clock() - startTimeForDescending2 << "ms" << endl;
    clock_t startTimeForDescending3 = clock();
    quickSort(arrayInDescendingOrder3, 0, 9999);
    cout << "Time taken to sort arrayInDescendingOrder3 using quick sort: " << clock() - startTimeForDescending3 << "ms" << endl;
    clock_t startTimeForDescending4 = clock();
    quickSort(arrayInDescendingOrder4, 0, 99999);
    cout << "Time taken to sort arrayInDescendingOrder4 using quick sort: " << clock() - startTimeForDescending4 << "ms" << endl;
    clock_t startTimeForDescending5 = clock();
    quickSort(arrayInDescendingOrder5, 0, 999999);
    cout << "Time taken to sort arrayInDescendingOrder5 using quick sort: " << clock() - startTimeForDescending5 << "ms" << endl;
    return 0;
}