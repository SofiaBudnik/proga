#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

#define STUDENTS_AMOUNT 29

#define MAX_STRING_LENGTH 80

int main()
{
    FILE* fin;
    FILE* fout;
    int counter;
    char** students = (char**)malloc(STUDENTS_AMOUNT * sizeof(char*));
    for (counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
        students[counter] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    }
    if (!(fin = fopen("input.txt", "r"))) {
        printf("File can't be open");
        exit(1);
    }
    for (counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
        fgets(students[counter], MAX_STRING_LENGTH, fin);
    }
    sort(students, 0);
    edit_names(students);
    if (!(fout = fopen("output.txt", "w"))) {
        printf("File can't be open");
        exit(1);
    }
    else {
        for (counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
            fputs(students[counter], fout);
        }
        fclose(fout);
        fclose(fin);
    }
    for (counter = 0; counter < STUDENTS_AMOUNT; ++counter) {
        free(students[counter]);
        students[counter] = NULL;
    }
    free(students);
    students = NULL;
    return 0;
}