//========================
//
//  Счетчик сзданных объектов
//
//
//========================


#include <iostream>

template<typename T>
int counter = 0;

struct Dog
{
    Dog() { counter<Dog>++; }
};

struct Cat
{
    Cat(){ counter<Cat>++; }
};

struct Parrot
{
    Parrot(){ counter<Parrot>++; }
};

int main()
{
    Dog dog1, dog2;
    Cat cat1, cat2, cat3;
    Parrot parrot1, parrot2, parrot3, parrot4;

    std::cout << "Number of dogs: " << counter<Dog> << std::endl;
    std::cout << "Number of cats: " << counter<Cat> << std::endl;
    std::cout << "Number of parrots: " << counter<Parrot> << std::endl;

    return 0;
}