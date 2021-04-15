#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

void enter_array(int*** arr, int height, int width);

void rows_deleting(int*** arr, int* height, int* width, int counter);

void cols_deleting(int*** arr, int* cols, int* height, int* width, int counter);

void edit_array(int*** arr, int* height, int* width);

int main()
{
    int height, width, i, j;
    printf("Enter height : ");
    scanf("%d", &height);
    printf("Enter width : ");
    scanf("%d", &width);
    int** arr = NULL;
    enter_array(&arr, height, width);
    edit_array(&arr, &height, &width);
    system("cls");
    printf("Your edited array:\n");
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}