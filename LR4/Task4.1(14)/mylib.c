#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylib.h"

#define MAX_STRINGS_AMOUNT 10

#define MAX_STRING_LENGTH 80

vowels get_info(char str[MAX_STRINGS_AMOUNT][MAX_STRING_LENGTH])
{
    vowels vow;
    vow.a_amount = 0;
    vow.e_amount = 0;
    vow.i_amount = 0;
    vow.o_amount = 0;
    vow.u_amount = 0;
    vow.y_amount = 0;
    int i, j;
    for (i = 0; i < MAX_STRINGS_AMOUNT; ++i) {
        for (j = 0; j < strlen(str[i]); ++j) {
            switch (str[i][j])
            {
            case 'A':
                ++vow.a_amount;
                break;

            case 'a':
                ++vow.a_amount;
                break;

            case 'E':
                ++vow.e_amount;
                break;

            case 'e':
                ++vow.e_amount;
                break;

            case 'I':
                ++vow.i_amount;
                break;

            case 'i':
                ++vow.i_amount;
                break;

            case 'O':
                ++vow.o_amount;
                break;

            case 'o':
                ++vow.o_amount;
                break;

            case 'U':
                ++vow.u_amount;
                break;

            case 'u':
                ++vow.u_amount;
                break;

            case 'Y':
                ++vow.y_amount;
                break;

            case 'y':
                ++vow.y_amount;
                break;
            }
        }
    }
    return vow;
}

void get_diagram(vowels vow)
{
    int counter;
    printf("a - ");
    for (counter = 0; counter < vow.a_amount; ++counter)
        printf("+");
    printf("\ne - ");
    for (counter = 0; counter < vow.e_amount; ++counter)
        printf("+");
    printf("\ni - ");
    for (counter = 0; counter < vow.i_amount; ++counter)
        printf("+");
    printf("\no - ");
    for (counter = 0; counter < vow.o_amount; ++counter)
        printf("+");
    printf("\nu - ");
    for (counter = 0; counter < vow.u_amount; ++counter)
        printf("+");
    printf("\ny - ");
    for (counter = 0; counter < vow.y_amount; ++counter)
        printf("+");
}