#include <math.h>
#include <stdio.h>

int storonaA(int x1,int y1,int x2,int y2) {
   return sqrt(pow((x2-x1),2)+pow((y2-y1),2)); 
}
int storonaB(int x2,int y2, int x3,int y3) {
   return sqrt(pow((x3-x2),2)+pow((y3-y2),2));
}
int storonaC(int x1,int y1,int x3,int y3) {
   
   return sqrt(pow((x1-x3),2)+pow((y1-y3),2));
}
 void proverka(int a, int b, int c) {
   if(a==b && b==c && c==a) {
      printf ("Regular triangle\n");
   }
   else if (a==b || a==c || b==c) {
      printf ("Isosceles triangle\n");
   }
   else printf ("Versatile triangle\n");

 }

int perimeter (int a,int b, int c) {
   return a+b+c; 
}
int squared(int a, int b, int c)
{
    int p,S;

    p=(a+b+c)/2;
    S=sqrt(p*(p-a)*(p-b)*(p-c));

    return S;
    
}
  int main () {
  int x1,y1,x2,y2,x3,y3;
  int N;
  int a,b,c;

  printf ("Enter coordinaty\n");
  scanf("%d",&x1);
  scanf("%d",&y1);
  scanf("%d",&x2);
  scanf("%d",&y2);
  scanf("%d",&x3);
  scanf("%d",&y3);
  
  a=storonaA(x1,y1,x2,y2);
  b=storonaB(x2,y2,x3,y3);
  c=storonaC(x3,y3,x1,y1);

   if(a+b>c && a+c>b && b+c>a) {

       printf("This triangle exist\n");

   }
   else {
      printf("This triangle don't exist!\n");
      return 0;
    }

  printf("1.Proverka\n");
  printf("2.Perimeter\n");
  printf ("3.Square\n");
  printf ("4.Autor\n");
  printf ("5.Exit\n");

  scanf("%d",&N);
  switch(N){
   case 1: 
      proverka(a,b,c);
      break;
   case 2:
      printf ("%dP=",perimeter(a,b,c));

      break;
   case 3:
      printf("%dS=",squared (a,b,c));
      break;
   case 4:
   printf("Autor-Budnik Sofia");
   break;
   case 5:
   return 0;   
  default: printf("Error");
  
  }
  return 0;
  }



  