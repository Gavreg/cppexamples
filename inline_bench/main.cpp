//=============================================
//
// Проверка скорости работы inline и no inline функций.
// 
//
// компилировать g++ main.cpp -o main -O2  
// O2 - оптимизация, которая включает в себя inline функции, но не гарантирует их использование.
// O3 - более агрессивная оптимизация, которая может включать в себя больше inline функций, но также не гарантирует их использование.
//=============================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO_INLINE __attribute__((noinline))

inline int sum_inline(int a, int b)
{
    return a + b;
}

NO_INLINE int sum_no_inline(int a, int b)
{
    return a + b;
}

int main(int argc, char* argv[])
{
    int count = 1000000000;
    if (argc >= 2)
    {
        count = atoi(argv[1]);
    }

    clock_t start, end;
    double cpu_time_used;

    // Тестирование inline функции

    start = clock();
    int result_inline = 0;
    for (int i = 0; i < count; ++i)
    {
        result_inline += sum_inline(i, i);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Inline function result: %d, Time taken: %f seconds\n", result_inline, cpu_time_used);

    // Тестирование no_inline функции

    start = clock();
    int result_no_inline = 0;
    for (int i = 0; i < count; ++i)
    {
        result_no_inline += sum_no_inline(i, i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("No-inline function result: %d, Time taken: %f seconds\n", result_no_inline, cpu_time_used);

}
