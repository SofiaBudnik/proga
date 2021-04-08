#include "main.c"
#include <assert.h>
#include <stdio.h>

int test_bintodec() {
    assert(bintodec("0001",4)==1);    
    assert(bintodec("1001",4)==9);
}
#undef main
int main () {
    printf ("\n\n%c\n\n", bintodec("0001",4));
    test_bintodec();
}