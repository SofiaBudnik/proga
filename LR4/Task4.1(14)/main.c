#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

#define MAX_STRINGS_AMOUNT 10

#define MAX_STRING_LENGTH 80

int main()
{
    char text[MAX_STRINGS_AMOUNT][MAX_STRING_LENGTH];
    printf("Please, enter your text : ");
    int i;
    for (i = 0; i < MAX_STRINGS_AMOUNT; ++i) {
        fgets(text[i], 80, stdin);
    }
    system("cls");
    vowels vow = get_info(text);
    get_diagram(vow);
    return 0;
}