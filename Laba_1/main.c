#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
char *itoa(int number, char *destination, int base) {
  int count = 0;
  int i;
  do {
    int digit = number % base;
    destination[count++] = (digit > 9) ? digit - 10 +'A' : digit + '0';
  } while ((number /= base) != 0);
  destination[count] = '\0';

  for (i = 0; i < count / 2; ++i) {
    char symbol = destination[i];
    destination[i] = destination[count - i - 1];
    destination[count - i - 1] = symbol;
  }
  return destination;
}
size_t str_len (const char *str)
{
    return (*str) ? str_len(++str) + 1 : 0;
}

char vychislen(int k)
{
   char a[30];
   int i=1;
    while(k>0) {
        itoa(i*i*i, a, 10);
        k -= str_len(a);
        i++;
    }
     k += str_len(a);
  return a[k-1];
  

}
/*
int main ()
{
    int i,k;
    char a[30];

    printf ("182764125216343512...\n");

    printf ("Enter k: ");
    scanf("%d",&k);
    
    //vychislen (a,k);
     i=1;

    while(k>0) {
        itoa(i*i*i, a, 10);
        int count = 0;
        k -= strlen(a);
        i++;
    }
    return
     k += strlen(a);

    printf("%c",a[k-1]);
    
    getch ();
    return 0;

}*/

 
int main ()
{
    int i,k;
    
    printf ("182764125216343512...\n");

    printf ("Enter k: ");
 
    scanf("%d",&k);
 
    printf("%c",vychislen(k));
    return 0;
}