#include <stdlib.h>
#include <stdio.h>

int main()
{
    char name[10];
    printf("Enter your name: ");
    fgets(name, 10, stdin);
    printf("Hello %s \n", name);

    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You are %d \n", age);

    char grade;
    printf("Enter your grade: ");
    scanf("%c", &grade);
    printf("You got an %c on the test \n", grade);

    double gpa;
    printf("Enter your gpa: ");
    scanf("%lf", &gpa);
    printf("Your gpa is %f \n", gpa);
}