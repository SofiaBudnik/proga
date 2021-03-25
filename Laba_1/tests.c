#include "main.h"
#include <assert.h>

int test_vychislen(char a[30]) {
    assert(vychislen(a[4],5)==6);
}

#undef main
int main () {
    char a[30]={1,2,7,6,4,1,2,5};
    test_vychislen(a);
}
 