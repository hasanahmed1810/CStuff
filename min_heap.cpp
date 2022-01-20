#include<iostream>
#include <cmath>

using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap {
    int *array; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int size);

    // to heapify a subtree with the root at given index
    void MinHeapify(int);

    int parent(int i) { return (i - 1) / 2; }

    // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to newValue
    void decreaseKey(int index, int newValue);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return array[0]; }

    // Deletes a key stored at index i
    void deleteKey(int index);

    // Inserts a new key 'key'
    void insertKey(int key);

    // array representation of a heap
    void print();

    // returns the current number of elements in min heap
    int size();

    // checks if the array is empty or not
    bool isEmpty();

    // returns the height of the tree
    int height();

    // builds a heap using array input
    void buildHeap(int *arrayInput, int size);
};

// Constructor: Builds a heap of given size
MinHeap::MinHeap(int size) {
    heap_size = 0;
    capacity = size;
    array = new int[size];
}

// Inserts a new key
void MinHeap::insertKey(int key) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    array[i] = key;

    // Fix the min heap property if it is violated
    while (i != 0 && array[parent(i)] > array[i]) {
        swap(&array[i], &array[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index to newValue. It is assumed that
// newValue is smaller than array[index].
void MinHeap::decreaseKey(int index, int newValue) {
    array[index] = newValue;
    while (index != 0 && array[parent(index)] > array[index]) {
        swap(&array[index], &array[parent(index)]);
        index = parent(index);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return array[0];
    }

    // Store the minimum value, and remove it from heap
    int root = array[0];
    array[0] = array[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}


// This function deletes key at index . It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int index) {
    decreaseKey(index, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int index) {
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if (l < heap_size && array[l] < array[index])
        smallest = l;
    if (r < heap_size && array[r] < array[smallest])
        smallest = r;
    if (smallest != index) {
        swap(&array[index], &array[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::print() {
    for (int i = 0; i < heap_size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int MinHeap::size() {
    return heap_size;
}

bool MinHeap::isEmpty() {
    return heap_size == 0;
}

void MinHeap::buildHeap(int *arrayInput, int size) {

    heap_size = 0;
    capacity = size;
    array = new int[size];

    for (int i = 0; i < size; i++) {
        insertKey(arrayInput[i]);
    }

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = size; i >= 0; i--) {
        MinHeapify(i);
    }
}

int MinHeap::height() {
    return ceil(log2(heap_size + 1)) - 1;
}

// A utility function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Driver program to test above functions
int main() {
    MinHeap minHeap(11);
    minHeap.insertKey(3);
    minHeap.insertKey(2);
    minHeap.deleteKey(1);
    minHeap.insertKey(15);
    minHeap.insertKey(5);
    minHeap.insertKey(4);
    minHeap.insertKey(45);
    minHeap.insertKey(80);
    cout << "Minimum extracted: " <<minHeap.extractMin() << endl;
    cout << "Getting minimum: " << minHeap.getMin() << endl;
    cout << "decreasing key at index 2" << endl;
    minHeap.decreaseKey(2, 1);
    cout << "Getting minimum: " << minHeap.getMin() << endl;
    cout << "Printing the array representation of the min heap" << endl;
    minHeap.print();
    cout << "Heap size: " << minHeap.size() << endl;
    cout << "Heap height: " << minHeap.height() << endl;
    cout << endl;
    cout << "Building a heap using an array input" << endl;
    int *array = new int[10]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    minHeap.buildHeap(array, 10);
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "Printing the array representation of the min heap" << endl;
    minHeap.print();
    return 0;
}
