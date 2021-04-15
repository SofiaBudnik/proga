#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mylib.h"

#define STUDENTS_AMOUNT 29

#define MAX_STRING_LENGTH 80

void q_sort(char** stud, int left, int right, int poz)
{
    int l = left, r = right;
    char* temp = NULL;
    char* root = stud[(l + r) / 2];
    do {
        while (stud[l][poz] < root[poz]) {
            ++l;
        }
        while (stud[r][poz] > root[poz]) {
            --r;
        }
        if (l <= r) {
            temp = stud[l];
            stud[l] = stud[r];
            stud[r] = temp;
            ++l;
            --r;
        }
    } while (l < r);
    if (left < r) q_sort(stud, left, r, poz);
    if (right > l) q_sort(stud, l, right, poz);
}

void sort(char** stud, int poz)
{
    q_sort(stud, 0, STUDENTS_AMOUNT - 1, poz);
    int i, temp;
    bool isSort;
    while (poz != 5) {
        for (i = 0; i < STUDENTS_AMOUNT - 1; ++i) {
            isSort = false;
            temp = i;
            while (i < STUDENTS_AMOUNT - 1 && stud[i][poz] == stud[i + 1][poz]) {
                if (stud[i][0] < stud[i + 1][0])
                    break;
                isSort = true;
                ++i;
            }
            if(isSort)
                q_sort(stud, temp, i, poz + 1);
        }
        ++poz;
    }
}

void to_upper_case(char* name)
{
    int counter;
    for (counter = 0; counter < strlen(name); ++counter) {
        if (name[counter] != ' ')
            continue;
        while (name[counter] == ' ')
            ++counter;
        if (name[counter] > 90) {
            name[counter] -= 32;
            break;
        }
    }
}

void edit_names(char** stud)
{
    int counter;
    for (counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
        to_upper_case(stud[counter]);
    }
}