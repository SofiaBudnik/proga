#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
int vychislen(char a[30], int k)
{
    int i=1;

    while(k>0) {
        itoa(i*i*i, a, 10);
        k -= strlen(a);
        i++;
    }
    return k += strlen(a);

}

int main ()
{
    int i,k;
    char a[30];

    printf ("182764125216343512...\n");

    printf ("Enter k: ");
    scanf("%d",&k);
    
    vychislen (a,k);

    printf("%c",a[k-1]);
    

    return 0;

}