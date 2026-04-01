#include <iostream>
//=================================
//
//Пример использования SFINAE(Substitution Failure Is Not An Error) 
//для проверки наличия метода Hello() в классе T.
//
//          g++ -std=c++11 main.cpp -o main //работает даже в 11 стандарте с++.
//=================================


struct A
{
    void Hello()
    {
        std::cout << "Hello from A!" << std::endl;
    }
};

struct B
{
    void Hi()
    {
        std::cout << "Hi from B!" << std::endl;
    }
};

template <typename T>
class searchHello
{
    typedef char Yes[2];
    typedef char No[1];


    template <typename C, C>
    struct Check;

    template <typename U>
    static Yes& test(Check<void (U::*)(), &U::Hello>* );
    
    template <typename M>
    static No& test(...);
public:    
static const bool value = sizeof(test<T>(0)) == sizeof(Yes);
};


int main()
{
    std::cout << searchHello<A>::value << std::endl;
    std::cout << searchHello<B>::value << std::endl;
    return 0;
}

