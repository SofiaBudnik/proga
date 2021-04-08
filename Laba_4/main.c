#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
 
char* swap_min_max(char* s);
 
int main(void) {
    int proverka;
    char *mystr;
    mystr = malloc( sizeof(char) * 1536 );
    do {
    printf("Для работы программы введите предложение на Английском, пожалуйста.\n");
    gets(mystr);
    swap_min_max(mystr);
    puts(mystr);
    printf("Для продолжения работы программы введите 0!");
    scanf("%d",&proverka);
    fflush(stdin);
    } while (proverka==0);
    free(mystr);
 return 0;
 
 
}
 
char* swap_min_max(char* s){
    int   n1 = 0, n2 = 0, k = 0;
    char *p1, *p2, *e1, *e2;
    char *t, c, *p = s;
 
    //поиск мин/макс слова
    do {
        if(*p && !(*p==' ' || *p=='.' || *p==',' || *p=='!' || *p=='?'))
        ++k;
        else if(k > 0){
            if((k < n1) || !n1){
                n1 = k;
                p1 = p - k;
                e1 = p;
            }
 
            if(k > n2){
                n2 = k;
                p2 = p - k;
                e2 = p;
            }
            k = 0;
        }
 
    } while(*p++ != '\0');
 
    if(p1 > p2){
        t = p1, p1 = p2, p2 = t;
        t = e1, e1 = e2, e2 = t;
    }
 
    for(; p2!=e2; p2++){
        for(p = p2; p > p1; p--){
            c  = *p;
            *p = *(p - 1);
            *(p - 1) = c;
        }
        p1++;
        e1++;
    }
 
    for(--e2; p1 != e1; --e1){
        for(p = p1; p < e2; ++p){
            c  = *p;
            *p = *(p + 1);
            *(p + 1) = c;
        }
    }
    return s;
}