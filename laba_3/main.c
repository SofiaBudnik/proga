#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
int comp1 (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int bintodec(char *a, int n) {
  int sum,i=0;
    for (i=n-1;i>-1;i--)
   if (a[i]=='1')   
   return sum+=pow(2,i) ;
  }


int main()
{
  int **a;  
  int i, j, n, m, temp, d, b, r, c=0, min=0, x=0;
  int *y;
  char buffer[50];
  system("chcp 1251");
  system("cls");
  printf("Enter the number of lines: ");
  scanf("%d", &n);
  printf("Enter the number of columns: ");
  scanf("%d", &m);
  y=(int*)malloc(n*sizeof(int));
  a = (int**)malloc(n * sizeof(int*));
  if (!a) {
    printf("Incorrect value\n");
    system("pause");
    return 0;
  }
  for (i = 0; i<n; i++)  
  {
    a[i] = (int*)malloc(m * sizeof(int));
    for (j = 0; j<m; j++)  
    { r=rand()%2;
      a[i][j]=r;
    }
  }

  for (i = 0; i < n; i++)  
  { 
    for (j = 0; j < m; j++)  
    {
      printf("%5d ", a[i][j]); 
    }
    printf("\n");
  }
  for (i=0; i<n; i++) {
 buffer[i]+=a[1][i];
  }

  printf ("Unsorted:\n");
  /* for (i=0; i<n; i++) {
      d=m-1;
      for (j = 0; j < m; j++) {
        b+=a[i][j]*pow(2,d);
        d--;
      }
    y[c]=b;
    b = 0;
    printf("%d\n",y[c]);
    c++;
  }  */
  
  for (i=0;i<n;i++) {
  for (j=m-1;j>-1;j--) {
   if (a[i][j]==1)   
   b+=pow(2,i) ;
  }
  y[i]=b;
  printf("%d\n",y[i]);
  } 

   qsort (y, n, sizeof(int), comp1);
  printf("\nSorted:\n");

  for (i=0;i<n;i++)
    printf("%d \n",y[i]);

  
  for (i = 0; i < n; i++)  
    free(a[i]);  
  free(a);
  free(y);
  getchar(); getchar(); getchar();
  return 0;
}