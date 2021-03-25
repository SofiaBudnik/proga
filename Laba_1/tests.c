#include "main.h"
#include <assert.h>

int test_vychislen() {
    assert(vychislen(5)==6);
}

#undef main
int main () {
    test_vychislen();
}
 