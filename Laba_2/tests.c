#include "main.h"
#include <assert.h>
#include <stdio.h>


int test_storonaA() {
    assert(storonaA(200,200,300,100)==111);    
}
int test_storonaB() {
    assert(storonaB(300,100,400,200)==111);
}
int test_storonaC() {
    assert(storonaC(400,200,200,200)==111);
}
int test_perimeter () {
   assert(perimeter(111,111,111)==333);
}
int test_squared() {
    assert(squared(111,111,111)==5097);
}
#undef main
int main () {
    test_storonaA();
    test_storonaB();
    test_storonaC();
    test_perimeter ();
    test_squared();
    
}
 