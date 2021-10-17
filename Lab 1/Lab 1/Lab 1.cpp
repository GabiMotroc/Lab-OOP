// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "a.h"
#include "b.h"

void test()
{
    std::cout << "Test from main\n";
}

int main() 
{
    test();
    A::test();
    B::test();
    std::cout << A::getOS() << '\n';
}
