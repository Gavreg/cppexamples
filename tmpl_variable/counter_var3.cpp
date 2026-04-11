//========================
//
//  Счетчик сзданных объектов
//
//
//========================


#include <iostream>

struct Create_Tag {};
struct Destroy_Tag {};

template<typename T,typename Tag>
int counter = 0;

struct Dog
{
    Dog() { counter<Dog, Create_Tag>++; }
    ~Dog() { counter<Dog, Destroy_Tag>++; }
};

struct Cat
{
    Cat(){ counter<Cat, Create_Tag>++; }
    ~Cat(){ counter<Cat, Destroy_Tag>++; }
};

struct Parrot
{
    Parrot(){ counter<Parrot, Create_Tag>++; }
    ~Parrot(){ counter<Parrot, Destroy_Tag>++; }
};

int main()
{
    Dog dog1, dog2;
    Cat cat1, cat2, cat3;
    Parrot parrot1, parrot2, parrot3, parrot4;

    {
        Dog dog3;
        Cat cat4;
        Parrot parrot5, parrot6;
    }

    std::cout << "Number of created dogs: " << counter<Dog, Create_Tag> << std::endl;
    std::cout << "Number of created cats: " << counter<Cat, Create_Tag> << std::endl;
    std::cout << "Number of parrots: " << counter<Parrot, Create_Tag> << std::endl;

    std::cout << "Number of destroyed dogs: " << counter<Dog, Destroy_Tag> << std::endl;
    std::cout << "Number of destroyed cats: " << counter<Cat, Destroy_Tag> << std::endl;
    std::cout << "Number of destroyed parrots: " << counter<Parrot, Destroy_Tag> << std::endl;

    return 0;
}