#include <pthread.h>
#include <stdio.h>

#define FIRST_ODD_NUM 1
#define FIRST_EVEN_NUM 2
#define MAX 10

void *print_even_nums(void *param)
{
    int even_num_to_print;

    for (even_num_to_print = FIRST_EVEN_NUM; even_num_to_print < MAX;)
    {
        printf("%d ", even_num_to_print);
        even_num_to_print += 2;
    }
}

void *print_odd_nums(void *param)
{
    int odd_num_to_print;
    for (odd_num_to_print = FIRST_ODD_NUM; odd_num_to_print < MAX;)
    {
        printf("%d ", odd_num_to_print);
        odd_num_to_print += 2;
    }
}

int main(int argc, char *argv[])
{
    pthread_t even_thread;
    pthread_t odd_thread;

    pthread_create(&even_thread, NULL, print_even_nums, NULL);
    pthread_create(&odd_thread, NULL, print_odd_nums, NULL);

    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);
}
