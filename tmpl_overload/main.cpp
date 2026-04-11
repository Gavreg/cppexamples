//===================================
//
// Перегрузка и шаблоны
//
//
//===================================

#include <iostream>

void foo(int a)
{
    std::cout << "foo(int a) called with a = " << a << std::endl;
}

void foo(double a)
{
    std::cout << "foo(double a) called with a = " << a << std::endl;
}

void foo(int a, double b)
{
    std::cout << "foo(int a, double b) called with a = " << a << " and b = " << b << std::endl;
}

template<typename T>
void foo(T a)
{
    std::cout << "foo(T a) called with a = " << a << std::endl;
}

main ()
{
    foo(42);          // Вызовет foo(int a)
    foo(3.14);        // Вызовет foo(double a)
    foo(42, 3.14);    // Вызовет foo(int a, double b)
    foo(3.14f);       // ??
    
    return 0;
}