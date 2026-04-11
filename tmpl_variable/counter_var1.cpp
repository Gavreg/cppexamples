//========================
//
//  Счетчик сзданных объектов
//
//
//========================


#include <iostream>

int dog_counter = 0;
int cat_counter = 0;

struct Dog
{
    Dog() { dog_counter++; }
};

struct Cat
{
    Cat(){ cat_counter++; }
};

int main()
{
    Dog dog1, dog2;
    Cat cat1, cat2, cat3;

    std::cout << "Number of dogs: " << dog_counter << std::endl;
    std::cout << "Number of cats: " << cat_counter << std::endl;

    return 0;
}