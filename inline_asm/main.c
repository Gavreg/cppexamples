//=============================================
//
// Inline функции
// 
//
// компилировать g++ main.c -o main -O2 -S -masm=intel
// O2 - оптимизация, которая включает в себя inline функции, но не гарантирует их использование.
// O3 - более агрессивная оптимизация, которая может включать в себя больше inline функций, но также не гарантирует их использование.
//=============================================

#include <stdio.h>

#define NO_INLINE  __attribute__((noinline))

inline int my_sum(int a, int b)
{
    return a + b;
}


#define VAR1
int main(int argc, char* argv[])
{

#ifdef VAR1
    int a = my_sum(100,200);
    int b = my_sum(300,400);
    int c = my_sum(500,600);
#endif

#ifdef VAR2
    int a =  100 + 200;
    int b =  300 + 400;
    int c =  500 + 600;
#endif

    int d = a + b + c;
    printf("%d",d);
    return 0;
}
