#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void countingSort(int *array, int size) {

    int *output = new int[size];
    int *count_arr = new int[size];


    // find max
    int maxNumber = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maxNumber){
            maxNumber = array[i];
        }
    }


    // initialize array to zero
    for (int i = 0; i <= maxNumber; ++i) {
        count_arr[i] = 0;
    }

    //increase number count in count array
    // frequency distribution
    for (int i = 0; i < size; i++) {
        count_arr[array[i]]++;
    }

    // cumulative frequency distribution
    for (int i = 1; i <= maxNumber; i++) {
        count_arr[i] += count_arr[i - 1];
    }

    // where the sorting happens
    for (int i = size - 1; i >= 0; i--) {
        output[count_arr[array[i]] - 1] = array[i];
        count_arr[array[i]]--; // decrease count for the number
    }

    // copying sorted array into main array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(int *array, int size) {
    // Find the maximum number to know number of digits
    int max = array[0];
    // finding the max
    for (int i = 1; i < size; i++){
        if (array[i] > max){
            max = array[i];
        }
    }
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int place = 1; max / place > 0; place *= 10){

        int *output = new int[size]; // output array
        int i;
        int *count = new int[10]{0};

        // Store count of occurrences in count[]
        for (i = 0; i < size; i++)
            count[(array[i] / place) % 10]++;

        // Change count[i] so that count[i] now contains actual
        // position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = size - 1; i >= 0; i--) {
            output[count[(array[i] / place) % 10] - 1] = array[i];
            count[(array[i] / place) % 10]--;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (i = 0; i < size; i++)
            array[i] = output[i];
    }
}

void display(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
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

    clock_t startTimeCountingSortOnAscending1 = clock();
    countingSort(arrayInAscendingOrder1, 100);
    cout << "Time taken to sort arrayInAscendingOrder1 using counting sort: " << clock() - startTimeCountingSortOnAscending1 << "ms" << endl;
    clock_t startTimeCountingSortOnAscending2 = clock();
    countingSort(arrayInAscendingOrder2, 1000);
    cout << "Time taken to sort arrayInAscendingOrder2 using counting sort: " << clock() - startTimeCountingSortOnAscending2 << "ms" << endl;
    clock_t startTimeCountingSortOnAscending3 = clock();
    countingSort(arrayInAscendingOrder3, 10000);
    cout << "Time taken to sort arrayInAscendingOrder3 using counting sort: " << clock() - startTimeCountingSortOnAscending3 << "ms" << endl;
    clock_t startTimeCountingSortOnAscending4 = clock();
    countingSort(arrayInAscendingOrder4, 100000);
    cout << "Time taken to sort arrayInAscendingOrder4 using counting sort: " << clock() - startTimeCountingSortOnAscending4 << "ms" << endl;
    clock_t startTimeCountingSortOnAscending5 = clock();
    countingSort(arrayInAscendingOrder5, 1000000);
    cout << "Time taken to sort arrayInAscendingOrder5 using counting sort: " << clock() - startTimeCountingSortOnAscending5 << "ms" << endl;

    cout << endl;

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

    clock_t startTimeRadixSortOnAscending1 = clock();
    radixSort(arrayInAscendingOrder1, 100);
    cout << "Time taken to sort arrayInAscendingOrder1 using radix sort: " << clock() - startTimeRadixSortOnAscending1 << "ms" << endl;
    clock_t startTimeRadixSortOnAscending2 = clock();
    radixSort(arrayInAscendingOrder2, 1000);
    cout << "Time taken to sort arrayInAscendingOrder2 using radix sort: " << clock() - startTimeRadixSortOnAscending2 << "ms" << endl;
    clock_t startTimeRadixSortOnAscending3 = clock();
    radixSort(arrayInAscendingOrder3, 10000);
    cout << "Time taken to sort arrayInAscendingOrder3 using radix sort: " << clock() - startTimeRadixSortOnAscending3 << "ms" << endl;
    clock_t startTimeRadixSortOnAscending4 = clock();
    radixSort(arrayInAscendingOrder4, 100000);
    cout << "Time taken to sort arrayInAscendingOrder4 using radix sort: " << clock() - startTimeRadixSortOnAscending4 << "ms" << endl;
    clock_t startTimeRadixSortOnAscending5 = clock();
    radixSort(arrayInAscendingOrder5, 1000000);
    cout << "Time taken to sort arrayInAscendingOrder5 using radix sort: " << clock() - startTimeRadixSortOnAscending5 << "ms" << endl;

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

    clock_t startTimeCountingSortOnDescending1 = clock();
    countingSort(arrayInDescendingOrder1, 100);
    cout << "Time taken to sort arrayInDescendingOrder1 using counting sort: " << clock() - startTimeCountingSortOnDescending1 << "ms" << endl;
    clock_t startTimeCountingSortOnDescending2 = clock();
    countingSort(arrayInDescendingOrder2, 1000);
    cout << "Time taken to sort arrayInDescendingOrder2 using counting sort: " << clock() - startTimeCountingSortOnDescending2 << "ms" << endl;
    clock_t startTimeCountingSortOnDescending3 = clock();
    countingSort(arrayInDescendingOrder3, 10000);
    cout << "Time taken to sort arrayInDescendingOrder3 using counting sort: " << clock() - startTimeCountingSortOnDescending3 << "ms" << endl;
    clock_t startTimeCountingSortOnDescending4 = clock();
    countingSort(arrayInDescendingOrder4, 100000);
    cout << "Time taken to sort arrayInDescendingOrder4 using counting sort: " << clock() - startTimeCountingSortOnDescending4 << "ms" << endl;
    clock_t startTimeCountingSortOnDescending5 = clock();
    countingSort(arrayInDescendingOrder5, 1000000);
    cout << "Time taken to sort arrayInDescendingOrder5 using counting sort: " << clock() - startTimeCountingSortOnDescending5 << "ms" << endl;

    cout << endl;

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

    clock_t startTimeRadixSortOnDescending1 = clock();
    radixSort(arrayInDescendingOrder1, 100);
    cout << "Time taken to sort arrayInDescendingOrder1 using radix sort: " << clock() - startTimeRadixSortOnDescending1 << "ms" << endl;
    clock_t startTimeRadixSortOnDescending2 = clock();
    radixSort(arrayInDescendingOrder2, 1000);
    cout << "Time taken to sort arrayInDescendingOrder2 using radix sort: " << clock() - startTimeRadixSortOnDescending2 << "ms" << endl;
    clock_t startTimeRadixSortOnDescending3 = clock();
    radixSort(arrayInDescendingOrder3, 10000);
    cout << "Time taken to sort arrayInDescendingOrder3 using radix sort: " << clock() - startTimeRadixSortOnDescending3 << "ms" << endl;
    clock_t startTimeRadixSortOnDescending4 = clock();
    radixSort(arrayInDescendingOrder4, 100000);
    cout << "Time taken to sort arrayInDescendingOrder4 using radix sort: " << clock() - startTimeRadixSortOnDescending4 << "ms" << endl;
    clock_t startTimeRadixSortOnDescending5 = clock();
    radixSort(arrayInDescendingOrder5, 1000000);
    cout << "Time taken to sort arrayInDescendingOrder5 using radix sort: " << clock() - startTimeRadixSortOnDescending5 << "ms" << endl;

    return 0;
}