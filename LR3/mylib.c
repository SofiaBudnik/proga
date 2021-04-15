#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

void enter_array(int*** arr, int height, int width)
{
    int i, j;
    *arr = (int**)malloc(height * sizeof(int*));
    for (i = 0; i < height; ++i) {
        (*arr)[i] = (int*)malloc(width * sizeof(int));
    }
    printf("Enter an array :\n");
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            while (1) {
                if (!scanf("%d", &(*arr)[i][j]) || (*arr)[i][j] < 0 || (*arr)[i][j] > 1) {
                    printf("Wrong input, try again\n");
                    while (getchar() != '\n') { ; }
                }
                else {
                    break;
                }
            }
        }
    }
}

void rows_deleting(int*** arr, int* height, int* width, int counter)
{
    int i, j, NewI = 0;
    int** NewArr = (int**)malloc((*height - counter) * sizeof(int*));
    for (i = 0; i < *height - counter; ++i) {
        NewArr[i] = (int*)malloc(*width * sizeof(int));
    }
    for (i = 0; i < *height; ++i) {
        if ((*arr)[i]) {
            for (j = 0; j < *width; ++j) {
                NewArr[NewI][j] = (*arr)[i][j];
            }
            ++NewI;
        }
    }
    for (i = 0; i < *height; ++i) {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }
    free(*arr);
    *height -= counter;
    *arr = NewArr;
}

void cols_deleting(int*** arr, int* cols, int* height, int* width, int counter)
{
    int i, j, NewJ = 0, cols_counter = 0;
    int** NewArr = (int**)malloc(*height * sizeof(int*));
    for (i = 0; i < *height; ++i) {
        NewArr[i] = (int*)malloc((*width - counter) * sizeof(int));
    }
    for (j = 0; j < *width; ++j) {
        if (j == cols[cols_counter]) {
            ++cols_counter;
        }
        else {
            for (i = 0; i < *height; ++i) {
                NewArr[i][NewJ] = (*arr)[i][j];
            }
            ++NewJ;
        }
    }
    for (i = 0; i < *height; ++i) {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }
    free((*arr));
    *width -= counter;
    *arr = NewArr;
}

void edit_array(int*** arr, int* height, int* width)
{
    bool isOne = true;
    int i, j, sum = 0, counter = 0;
    for (i = 0; i < *height; ++i) {
        for (j = 0; j < *width; ++j) {
            if (!(*arr)[i][j]) {
                isOne = false;
                break;
            }
        }
        if (isOne) {
            ++counter;
            free((*arr)[i]);
            (*arr)[i] = NULL;
        }
        isOne = true;
    }
    rows_deleting(arr, height, width, counter);
    counter = 0;
    int* cols = (int*)malloc(*width * sizeof(int));
    int cols_couter = 0;
    for (j = 0; j < *width; ++j) {
        for (i = 0; i < *height; ++i) {
            if (!(*arr)[i][j]) {
                isOne = false;
                break;
            }
        }
        if (isOne) {
            cols[cols_couter] = j;
            ++cols_couter;
            ++counter;
        }
        isOne = true;
    }
    cols_deleting(arr, cols, height, width, counter);
    free(cols);
}