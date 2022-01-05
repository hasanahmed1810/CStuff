#include <stdlib.h>
#include <stdio.h>

int main()
{

    int index = 1;
    while (index <= 5)
    {
        printf("%d", index);
        index++;
    }

    printf("\n");

    index = 1;
    do
    {
        printf("%d", index);
        index++;
    } while (index <= 5);

    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d", i);
    }
}