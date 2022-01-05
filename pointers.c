#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 10;
    printf("%p \n", &num);

    int *pNum = &num;
    printf("%p \n", pNum);
    printf("%d \n", *pNum); // dereferencing
}