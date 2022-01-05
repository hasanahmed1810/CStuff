#include <iostream>
#include <pthread.h>

// size of array
#define MAX 100

// maximum number of threads
#define MAX_THREAD 4

using namespace std;

int a[MAX] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100 };
int localSums[4] = { 0 }; // initializes array with zero
int part = 0;

void* sum_array(void* arg)
{

	// Each thread computes sum of 1/4th of array
	int thread_part = part++;
	cout << part << endl; // just for checking

	for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++){
		localSums[thread_part] += a[i];
	}
}

int main()
{

	pthread_t threads[MAX_THREAD];

	// Creating 4 threads
	for (int i = 0; i < MAX_THREAD; i++)
		pthread_create(&threads[i], NULL, sum_array, (void*)NULL);

	// joining 4 threads i.e. waiting for all 4 threads to complete
	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);

	// adding sum of all 4 parts
	int total_sum = 0;
	for (int i = 0; i < MAX_THREAD; i++)
		total_sum += localSums[i];

	cout << "sum is " << total_sum << endl;

	return 0;
}