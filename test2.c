#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void main(void){
    int *a;
    a = (int *)malloc(sizeof(int)*10);
    printf("a = %p\n", a);
    int64_t b;
    b = (int64_t)a;
    printf("b = %ld\n", b);

    b = (intptr_t)a + 16;
    printf("b = %ld\n", b);

    printf("sizeof(a) = %ld\n", sizeof(intptr_t));
    printf("%ld\n", (int64_t)NULL);



}