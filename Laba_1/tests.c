#include "main.h"
#include <assert.h>

char test_vychislen() {
    assert(vychislen(5)==6);
}

#undef main
int main () {
    printf ("\n\n%c\n\n", vychislen(5));
    test_vychislen();
}
 