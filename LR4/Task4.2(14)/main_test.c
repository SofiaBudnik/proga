#include "mylib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STUDENTS_AMOUNT 29

#define MAX_STRING_LENGTH 80

void test() {
    FILE* fin;
    FILE* fin_test;
    int counter;
    char** students = (char**)malloc(STUDENTS_AMOUNT * sizeof(char*));
    for (counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
        students[counter] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    }
    char test_string[MAX_STRING_LENGTH];
    if (!(fin = fopen("input.txt", "r"))) {
        printf("File can't be open");
        exit(1);
    }
    if (!(fin_test = fopen("test.txt", "r"))) {
        printf("File can't be open");
        exit(1);
    }
    for (counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
        fgets(students[counter], MAX_STRING_LENGTH, fin);
    }
    sort(students, 0);
    edit_names(students);
    for(counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
       fgets(test_string, MAX_STRING_LENGTH, fin_test);
       assert(!strcmp(students[counter], test_string));
    }
}

#undef main

int main()
{
   test();
   return 0;
}