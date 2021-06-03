<<<<<<< Updated upstream

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

void testIsGreater(int** arr)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            assert(IsGreater(arr[j-1], arr[j]) == 0);
            
        }
    }    
}

void testIsSimilar(int** arr)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            assert(IsSimilar(arr[i],arr[j]) == 1);
        }
    } 
}

int main()
{    
    int **arr;
    n = 2;
    m = 3;
    arr = (int **)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++ )
        {
            arr[i][j] = 1;
        }
    }
    testIsGreater(arr);
    testIsSimilar(arr);
    
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    
    free(arr);
    printf("Tests passed succesfully\n");

    
    return 0;
}
=======

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"
#include <conio.h>
void testIsGreater(int** arr)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            assert(IsGreater(arr[j-1], arr[j]) == 0);
            
        }
    }    
}

void testIsSimilar(int** arr)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            assert(IsSimilar(arr[i],arr[j]) == 1);
        }
    } 
}

int main()
{    
    int **arr;
    n = 2;
    m = 3;
    arr = (int **)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++ )
        {
            arr[i][j] = 1;
        }
    }
    testIsGreater(arr);
    testIsSimilar(arr);
    
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    
    free(arr);
    printf("Tests passed succesfully\n");

    _getch();
    return 0;
}
>>>>>>> Stashed changes
