#include "vychislen.h"
#include <assert.h>

int test_vychislen(char a[30]) {
    assert(vychislen(a[30],5)==6);
}

#undef main
int main () {
    char a[30];
    test_vychislen(a);
}
 