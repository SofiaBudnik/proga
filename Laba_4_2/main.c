#include <stdio.h>
#include <stdlib.h>
#define n 128 
#define max_amount_of_string 28
#define max_string_size 100
int myAtoi(char *str)
{
    int res = 0; 
    
    for (int i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';

    
    return res;
}

 
int main(void)
{
    FILE *ptr_file;
    FILE *ptr_file_2;
    char **array;
    char buffer[n];
    char buffer_2[n];        
    int i,j;
 
    ptr_file=fopen("data.txt","r");
    if(ptr_file == NULL)
       {
          perror("Error in opening file");
          return(-1);
       }
    
    ptr_file_2=fopen("data_2.txt","r");
    if(ptr_file_2 == NULL)
       {
          perror("Error in opening file");
          return(-1);
       }
 
   for (i=0; i<max_amount_of_string; i++) {
       array[i]=(char*)malloc(max_string_size*sizeof(char));
   }
   // fseek(ptr_file, seek_max_word, SEEK_SET);   // устанавливаем нужное смещение
    for (i=0; i<max_amount_of_string; i++) {
        fgets(array[i],max_string_size,ptr_file_2);
    }
    for (i=0; i<max_amount_of_string; i++) {
        printf("%s",array[i]);
    }

    for(i = 0; i <15; i++) {    // читаем нужное слово по символам
        printf("%c", fgetc(ptr_file));
    }
    for(i = 0; i <15; i++) { 
        printf("%c", fgetc(ptr_file_2));
    }
    
    if ( NULL != fgets ( buffer, 128, ptr_file_2 )){
        printf("%s ",buffer);
    }

    fclose(ptr_file_2);
    fclose(ptr_file);
 
    
    return (0);
}