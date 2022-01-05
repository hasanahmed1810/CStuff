#include <stdio.h>
#include <stdlib.h>

int main()
{

   /*
Names are case-sensitive and may begin with:
     letters, _
After, may include
     letters, numbers, _
Convention says
     Start with a lowercase word, then additional words are capitalized
     ex. myFirstVariable
*/
   char testGrade = 'A'; // single 8-bit character.
   char name[] = "Mike"; // array of characters (string)

   // you can make them unsigned by adding "unsigned" prefix
   short age0 = 10;     // atleast 16-bits signed integer
   int age1 = 20;       // atleast 16-bits signed integer (not smaller than short)
   long age2 = 30;      // atleast 32-bits signed integer
   long long age3 = 40; // atleast 64-bits signed integer

   float gpa0 = 2.5;       // single percision floating point
   double gpa1 = 3.5;      // double-precision floating point
   long double gpa2 = 3.5; // extended-precision floating point

   int isTall; // 0 if false, non-zero if true
   isTall = 1;

   testGrade = 'F';

   printf("%s, your grade is %c \n", name, testGrade);

   printf("%d \n", (int)3.14);
   printf("%f \n", (double)3 / 2);

   /*
%c	character
%d	integer number (base 10)
%e	exponential floating-point number
%f	floating-point number
%i	integer (base 10)
%o	octal number (base 8)
%s	a string of characters
%u	unsigned decimal (integer) number
%x	number in hexadecimal (base 16)
%%	print a percent sign
\%	print a percent sign
*/
}