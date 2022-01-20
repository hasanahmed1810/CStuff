#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void bubbleSort(int array[], int size) {
    for (int j = 0; j < size - 1; ++j) {
        for (int i = 0; i < size - j - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int data[], int size){
    int i;
    int j;
    for(i = 1; i < size; i++){
        int temp = data[i];
        for(j = i; j > 0 && temp < data[j-1]; j--){
            data[j] = data[j-1];
        }
        data[j] = temp;
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
    int arrayInAscendingOrder1[100];
    int arrayInAscendingOrder2[1000];
    int arrayInAscendingOrder3[10000];
    int arrayInAscendingOrder4[100000];

    fillArrayWithRandomNumbers(arrayInAscendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInAscendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder4, 100000);

    sortArrayInAscendingOrder(arrayInAscendingOrder1, 100);
    sortArrayInAscendingOrder(arrayInAscendingOrder2, 1000);
    sortArrayInAscendingOrder(arrayInAscendingOrder3, 10000);
    sortArrayInAscendingOrder(arrayInAscendingOrder4, 100000);

    clock_t startTimeBubbleSortOnAscending1 = clock();
    bubbleSort(arrayInAscendingOrder1, 100);
    cout << "Time taken to sort arrayInAscendingOrder1 using bubble sort: " << clock() - startTimeBubbleSortOnAscending1 << "ms" << endl;
    clock_t startTimeBubbleSortOnAscending2 = clock();
    bubbleSort(arrayInAscendingOrder2, 1000);
    cout << "Time taken to sort arrayInAscendingOrder2 using bubble sort: " << clock() - startTimeBubbleSortOnAscending2 << "ms" << endl;
    clock_t startTimeBubbleSortOnAscending3 = clock();
    bubbleSort(arrayInAscendingOrder3, 10000);
    cout << "Time taken to sort arrayInAscendingOrder3 using bubble sort: " << clock() - startTimeBubbleSortOnAscending3 << "ms" << endl;
    clock_t startTimeBubbleSortOnAscending4 = clock();
    bubbleSort(arrayInAscendingOrder4, 100000);
    cout << "Time taken to sort arrayInAscendingOrder4 using bubble sort: " << clock() - startTimeBubbleSortOnAscending4 << "ms" << endl;

    cout << endl;

    fillArrayWithRandomNumbers(arrayInAscendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInAscendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder4, 100000);

    sortArrayInAscendingOrder(arrayInAscendingOrder1, 100);
    sortArrayInAscendingOrder(arrayInAscendingOrder2, 1000);
    sortArrayInAscendingOrder(arrayInAscendingOrder3, 10000);
    sortArrayInAscendingOrder(arrayInAscendingOrder4, 100000);

    clock_t startTimeSelectionSortOnAscending1 = clock();
    selectionSort(arrayInAscendingOrder1, 100);
    cout << "Time taken to sort arrayInAscendingOrder1 using selection sort: " << clock() - startTimeSelectionSortOnAscending1 << "ms" << endl;
    clock_t startTimeSelectionSortOnAscending2 = clock();
    selectionSort(arrayInAscendingOrder2, 1000);
    cout << "Time taken to sort arrayInAscendingOrder2 using selection sort: " << clock() - startTimeSelectionSortOnAscending2 << "ms" << endl;
    clock_t startTimeSelectionSortOnAscending3 = clock();
    selectionSort(arrayInAscendingOrder3, 10000);
    cout << "Time taken to sort arrayInAscendingOrder3 using selection sort: " << clock() - startTimeSelectionSortOnAscending3 << "ms" << endl;
    clock_t startTimeSelectionSortOnAscending4 = clock();
    selectionSort(arrayInAscendingOrder4, 100000);
    cout << "Time taken to sort arrayInAscendingOrder4 using selection sort: " << clock() - startTimeSelectionSortOnAscending4 << "ms" << endl;

    cout << endl;

    fillArrayWithRandomNumbers(arrayInAscendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInAscendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInAscendingOrder4, 100000);

    sortArrayInAscendingOrder(arrayInAscendingOrder1, 100);
    sortArrayInAscendingOrder(arrayInAscendingOrder2, 1000);
    sortArrayInAscendingOrder(arrayInAscendingOrder3, 10000);
    sortArrayInAscendingOrder(arrayInAscendingOrder4, 100000);

    clock_t startTimeInsertionSortOnAscending1 = clock();
    insertionSort(arrayInAscendingOrder1, 100);
    cout << "Time taken to sort arrayInAscendingOrder1 using insertion sort: " << clock() - startTimeInsertionSortOnAscending1 << "ms" << endl;
    clock_t startTimeInsertionSortOnAscending2 = clock();
    insertionSort(arrayInAscendingOrder2, 1000);
    cout << "Time taken to sort arrayInAscendingOrder2 using insertion sort: " << clock() - startTimeInsertionSortOnAscending2 << "ms" << endl;
    clock_t startTimeInsertionSortOnAscending3 = clock();
    insertionSort(arrayInAscendingOrder3, 10000);
    cout << "Time taken to sort arrayInAscendingOrder3 using insertion sort: " << clock() - startTimeInsertionSortOnAscending3 << "ms" << endl;
    clock_t startTimeInsertionSortOnAscending4 = clock();
    insertionSort(arrayInAscendingOrder4, 100000);
    cout << "Time taken to sort arrayInAscendingOrder4 using insertion sort: " << clock() - startTimeInsertionSortOnAscending4 << "ms" << endl;

    cout << endl;

    int arrayInDescendingOrder1[100];
    int arrayInDescendingOrder2[1000];
    int arrayInDescendingOrder3[10000];
    int arrayInDescendingOrder4[100000];

    fillArrayWithRandomNumbers(arrayInDescendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInDescendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder4, 100000);

    sortArrayInDescendingOrder(arrayInDescendingOrder1, 100);
    sortArrayInDescendingOrder(arrayInDescendingOrder2, 1000);
    sortArrayInDescendingOrder(arrayInDescendingOrder3, 10000);
    sortArrayInDescendingOrder(arrayInDescendingOrder4, 100000);

    clock_t startTimeBubbleSortOnDescending1 = clock();
    bubbleSort(arrayInDescendingOrder1, 100);
    cout << "Time taken to sort arrayInDescendingOrder1 using bubble sort: " << clock() - startTimeBubbleSortOnDescending1 << "ms" << endl;
    clock_t startTimeBubbleSortOnDescending2 = clock();
    bubbleSort(arrayInDescendingOrder2, 1000);
    cout << "Time taken to sort arrayInDescendingOrder2 using bubble sort: " << clock() - startTimeBubbleSortOnDescending2 << "ms" << endl;
    clock_t startTimeBubbleSortOnDescending3 = clock();
    bubbleSort(arrayInDescendingOrder3, 10000);
    cout << "Time taken to sort arrayInDescendingOrder3 using bubble sort: " << clock() - startTimeBubbleSortOnDescending3 << "ms" << endl;
    clock_t startTimeBubbleSortOnDescending4 = clock();
    bubbleSort(arrayInDescendingOrder4, 100000);
    cout << "Time taken to sort arrayInDescendingOrder4 using bubble sort: " << clock() - startTimeBubbleSortOnDescending4 << "ms" << endl;

    cout << endl;

    fillArrayWithRandomNumbers(arrayInDescendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInDescendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder4, 100000);

    sortArrayInDescendingOrder(arrayInDescendingOrder1, 100);
    sortArrayInDescendingOrder(arrayInDescendingOrder2, 1000);
    sortArrayInDescendingOrder(arrayInDescendingOrder3, 10000);
    sortArrayInDescendingOrder(arrayInDescendingOrder4, 100000);

    clock_t startTimeSelectionSortOnDescending1 = clock();
    selectionSort(arrayInDescendingOrder1, 100);
    cout << "Time taken to sort arrayInDescendingOrder1 using selection sort: " << clock() - startTimeSelectionSortOnDescending1 << "ms" << endl;
    clock_t startTimeSelectionSortOnDescending2 = clock();
    selectionSort(arrayInDescendingOrder2, 1000);
    cout << "Time taken to sort arrayInDescendingOrder2 using selection sort: " << clock() - startTimeSelectionSortOnDescending2 << "ms" << endl;
    clock_t startTimeSelectionSortOnDescending3 = clock();
    selectionSort(arrayInDescendingOrder3, 10000);
    cout << "Time taken to sort arrayInDescendingOrder3 using selection sort: " << clock() - startTimeSelectionSortOnDescending3 << "ms" << endl;
    clock_t startTimeSelectionSortOnDescending4 = clock();
    selectionSort(arrayInDescendingOrder4, 100000);
    cout << "Time taken to sort arrayInDescendingOrder4 using selection sort: " << clock() - startTimeSelectionSortOnDescending4 << "ms" << endl;

    cout << endl;

    fillArrayWithRandomNumbers(arrayInDescendingOrder1, 100);
    fillArrayWithRandomNumbers(arrayInDescendingOrder2, 1000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder3, 10000);
    fillArrayWithRandomNumbers(arrayInDescendingOrder4, 100000);

    sortArrayInDescendingOrder(arrayInDescendingOrder1, 100);
    sortArrayInDescendingOrder(arrayInDescendingOrder2, 1000);
    sortArrayInDescendingOrder(arrayInDescendingOrder3, 10000);
    sortArrayInDescendingOrder(arrayInDescendingOrder4, 100000);

    clock_t startTimeInsertionSortOnDescending1 = clock();
    insertionSort(arrayInDescendingOrder1, 100);
    cout << "Time taken to sort arrayInDescendingOrder1 using insertion sort: " << clock() - startTimeInsertionSortOnDescending1 << "ms" << endl;
    clock_t startTimeInsertionSortOnDescending2 = clock();
    insertionSort(arrayInDescendingOrder2, 1000);
    cout << "Time taken to sort arrayInDescendingOrder2 using insertion sort: " << clock() - startTimeInsertionSortOnDescending2 << "ms" << endl;
    clock_t startTimeInsertionSortOnDescending3 = clock();
    insertionSort(arrayInDescendingOrder3, 10000);
    cout << "Time taken to sort arrayInDescendingOrder3 using insertion sort: " << clock() - startTimeInsertionSortOnDescending3 << "ms" << endl;
    clock_t startTimeInsertionSortOnDescending4 = clock();
    insertionSort(arrayInDescendingOrder4, 100000);
    cout << "Time taken to sort arrayInDescendingOrder4 using insertion sort: " << clock() - startTimeInsertionSortOnDescending4 << "ms" << endl;

    return 0;
}