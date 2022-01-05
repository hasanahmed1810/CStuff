// CPP Program to find sum of array
#include <iostream>
#include <pthread.h>

// size of array
#define MAX 60

// maximum number of threads
#define MAX_THREAD 3

using namespace std;

int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60 };
int sum[3] = { 0 }; // initializes array with zero
int part = 0;

void* sum_array(void* arg)
{

	// Each thread computes sum of 1/3rd of array
	int thread_part = part++;
	cout << part << endl; // just for checking

	for (int i = thread_part * (MAX / 3); i < (thread_part + 1) * (MAX / 3); i++){
		sum[thread_part] += a[i];	
	}
}

// Driver Code
int main()
{

	pthread_t threads[MAX_THREAD];

	// Creating 3 threads
	for (int i = 0; i < MAX_THREAD; i++)
		pthread_create(&threads[i], NULL, sum_array, (void*)NULL);

	// joining 3 threads i.e. waiting for all 3 threads to complete
	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);

	// adding sum of all 3 parts
	int total_sum = 0;
	for (int i = 0; i < MAX_THREAD; i++)
		total_sum += sum[i];

	cout << "sum is " << total_sum << endl;

	return 0;
}