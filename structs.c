#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Book{
     char title[100];
     char author[100];
     int review;
};

int main()
{

      struct Book book1;
      strcpy( book1.title, "Harry Potter" );
      strcpy( book1.author, "JK Rowling");
      book1.review = 5;

      printf("%s \n", book1.title);
      printf("%d \n", book1.review);

      return 0;
}
