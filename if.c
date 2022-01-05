#include <stdlib.h>
#include <stdio.h>

int main()
{

    int isStudent = 0;
    int isSmart = 0;

    if (isStudent != 0 && isSmart != 0)
    {
        printf("You are a student\n");
    }
    else if (isStudent != 0 && isSmart == 0)
    {
        printf("You are not a smart student\n");
    }
    else
    {
        printf("You are not a student and not smart\n");
    }

    // >, <, >=, <=, !=, ==
    if (1 > 3)
    {
        printf("number omparison was true\n");
    }

    if ('a' > 'b')
    {
        printf("character comparison was true\n");
    }
}