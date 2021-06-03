<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#ifndef TEST
int main()
{
    int **arr;
 
    printf("Enter number of rows:\nn = ");
    n = CorrectInput();
    
    printf("Enter number of cols:\nm = ");
    m = CorrectInput();
    
    arr = (int **)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    
    ReadArray(arr);
    DeleteSimilar(arr);
    Sort(arr);
    WriteArray(arr);
    
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    
    free(arr);
    system("pause");
    return 0;
}
#endif

void ReadArray(int **arr)
{
    char *temp;
    temp = (char *)malloc(m * sizeof(char));
    
    for (i = 0; i < n; i++)
    {
        printf("Enter line %d: ", i + 1);
        scanf("%s", temp);
        for (j = 0; j < m; j++)
        {
            arr[i][j] = temp[j] - 48;
        }
    }
    
    printf("\n");
}
 
void WriteArray(int **arr)
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
 
int IsSimilar(int *arr1, int *arr2)
{
    for (i = 0; i < m; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}
 
int IsGreater(int *arr1, int *arr2) 
{
    for (i = 0; i < m; i++)
    {
        if (arr1[i] > arr2[i])
        {
            return 1;
        }
        else if (arr1[i] < arr2[i])
        {
            return 0;
        }
    }
    return 0;
}
 
void Sort(int **arr)
{
    int *temp;
 
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (IsGreater(arr[j-1], arr[j]))
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int CorrectInput()
{
  int temp;
  char goodCheck;

  while(!scanf("%d", &temp) || !scanf("%c", &goodCheck) || goodCheck != '\n')
  {
      printf("Wrong input! Please, try again: ");
      fflush(stdin);
  }

  return temp;
} 

void DeleteSimilar(int **arr)
{
    int *temp;
 
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (IsSimilar(arr[i], arr[j]))
            {
                temp = arr[n-1];
                arr[n-1] = arr[j];
                arr[j] = temp;
                j--;
                n--;
            }
        }
    }
=======
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#ifndef TEST
int main()
{
    int **arr;
 
    printf("Enter number of rows:\nn = ");
    n = CorrectInput();
    
    printf("Enter number of cols:\nm = ");
    m = CorrectInput();
    
    arr = (int **)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    
    ReadArray(arr);
    DeleteSimilar(arr);
    Sort(arr);
    WriteArray(arr);
    
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    
    free(arr);
    system("pause");
    return 0;
}
#endif

void ReadArray(int **arr)
{
    char *temp;
    temp = (char *)malloc(m * sizeof(char));
    
    for (i = 0; i < n; i++)
    {
        printf("Enter line %d: ", i + 1);
        scanf("%s", temp);
        for (j = 0; j < m; j++)
        {
            arr[i][j] = temp[j] - 48;
        }
    }
    
    printf("\n");
}
 
void WriteArray(int **arr)
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
 
int IsSimilar(int *arr1, int *arr2)
{
    for (i = 0; i < m; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}
 
int IsGreater(int *arr1, int *arr2) 
{
    for (i = 0; i < m; i++)
    {
        if (arr1[i] > arr2[i])
        {
            return 1;
        }
        else if (arr1[i] < arr2[i])
        {
            return 0;
        }
    }
    return 0;
}
 
void Sort(int **arr)
{
    int *temp;
 
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (IsGreater(arr[j-1], arr[j]))
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int CorrectInput()
{
  int temp;
  char goodCheck;

  while(!scanf("%d", &temp) || !scanf("%c", &goodCheck) || goodCheck != '\n')
  {
      printf("Wrong input! Please, try again: ");
      fflush(stdin);
  }

  return temp;
} 

void DeleteSimilar(int **arr)
{
    int *temp;
 
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (IsSimilar(arr[i], arr[j]))
            {
                temp = arr[n-1];
                arr[n-1] = arr[j];
                arr[j] = temp;
                j--;
                n--;
            }
        }
    }
>>>>>>> Stashed changes
}