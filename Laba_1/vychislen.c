#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

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