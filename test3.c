#include <stdio.h>
#include <stdint.h>
int compute(int64_t *A, void **B);

//#pragma address (io=0x0)
//int     io;                     //ioは0x0ffe00番地に配置

void main(){
    int64_t *a;
    //int64_t d = 10;
    //a = &d;
    void *b;
    int io = 0;
    int c = 100;

    int32_t f[5] = {0, 11, 22, 33, 44};
    char g[5] = "abcde";
    int32_t **h;
    int32_t *i;
    i = f;
    *(i+2) = 5;
    //*h = &io;
    printf("f = %p\n",f+1);
    printf("f = %p\n",f+2);
    printf("f = %p\n",f+3);
    printf("f = %p\n",f+4);
    printf("f = %p\n",f+5);
    printf("f = %p\n",f+6);        

    printf("f = %d\n",*f);
    printf("f = %d\n",*(f+2));
 
    printf("g = %c\n",*(g+6));
    //printf("f = %d\n",*(f+1));

    c = compute(a, b);
    //printf("c = %d\n", c);

    //int *d = (int *)0xffffffffffffffff;
    int *d = (int *)0x0000000000000000000000200004;
    char *e = "a";
    //*d = 1;
    //printf("io = %d\n", io);
    //printf("io = %p\n", &io);
    //printf("d = %d\n", *d);
    //printf("e = %s\n", e);
}

int compute(int64_t *A, void **B){
    int c = 0;
    //printf("A = %ld\n", *A);
    //c = *A + B;
    return c;
}