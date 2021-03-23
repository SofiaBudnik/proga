#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "main.h"

int main ()
{
    int i,k;
    char a[30];

    printf ("182764125216343512...\n");

    printf ("Enter k: %n");
    scanf("%d",&k);
    
    vychislen (a,k);

    printf("%c",a[k-1]);
    
    //getch();

    return 0;

}