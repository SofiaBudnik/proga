#include "main.h"
#include <assert.h>
#include <stdio.h>

char swap_min_max() {
    assert(swap_min_max("fdgdf dfg d")=='d');
}

#undef main
int main () {
    test_swap_min_max();
}
 