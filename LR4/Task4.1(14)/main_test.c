#include "mylib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRINGS_AMOUNT 10

#define MAX_STRING_LENGTH 80

void test() {
   char text[MAX_STRINGS_AMOUNT][MAX_STRING_LENGTH] = { "New blood joins this Earth", "And quickly he's subdued",\
   "Through constant pained disgrace", "The young boy learns their rules", "With time the child draws in",\
   "This whipping boy done wrong", "Deprived of all his thoughts", "The young man struggles on and on, he's knows",\
   "Ooh, a vow unto his own", "That never from this day" };
   vowels vow_test = get_info(text);
   assert(vow_test.a_amount == 13);
   assert(vow_test.e_amount == 20);
   assert(vow_test.i_amount == 17);
   assert(vow_test.o_amount == 22);
   assert(vow_test.u_amount == 10);
   assert(vow_test.y_amount == 6);
}

#undef main

int main()
{
   test();
   return 0;
}