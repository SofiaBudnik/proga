#include <stdio.h>
#include <stdlib.h>

 
int main(void)
{
    FILE *file = fopen("test.txt", "r");
    FILE *file2 = fopen("test2.txt", "r");
    char array_1[30][100], array_2[30][100], srav=0;
    int i,j;

    if(file == NULL) {
          perror("Error in opening file");
          return(-1);
    }
    if(file2 == NULL) {
          perror("Error in opening file");
          return(-1);
    }
    for (i=0;i<4;i++) {
    fgets(array_1[i], 255, file);
    printf("%s", array_1[i]);
    }
    printf("\n");
    for (i=0;i<4;i++) {
    fgets(array_2[i], 255, file2);
    
    printf("%s\n", array_2[i]);
    }
     while ((srav = fgetc(file2)) != EOF){
        if (srav >= 48 && srav<=57)                              
            printf("%c",srav);             
    }
    for (i=0;i<4;i++) {
        for (j=0;j<100;j++) {
            srav=array_2[i][j];
            if (srav==51)
             printf("%c\n", srav);
        }
    } 
    
   
    fclose(file);
    fclose(file2);
        
    return (0);
}