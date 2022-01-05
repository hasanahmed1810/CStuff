#include <stdlib.h>
#include <stdio.h>

int main()
{

    // int luckyNumbers[6];
    int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
    //        indexes:    0  1  2   3   4   5
    luckyNumbers[0] = 90;
    printf("%d \n", luckyNumbers[0]);
    printf("%d \n", luckyNumbers[1]);

    // int  numberGrid[2][3];
    int numberGrid[2][3] = {{1, 2, 3}, {4, 5, 6}};
    numberGrid[0][1] = 99;

    printf("%d \n", numberGrid[0][0]);
    printf("%d \n", numberGrid[0][1]);
}