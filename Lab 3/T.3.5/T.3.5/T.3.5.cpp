// T.3.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Complex
{
public:
    int real;
    int imaginary;
    Complex(){}
    Complex(int real, int imaginary) 
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    Complex operator +(const Complex& obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imaginary = imaginary + obj.imaginary;
        return temp;
    }
};

int main()
{
    Complex a(2, 3);
    Complex b(3, 5);
    Complex c = a + b;
    std::cout << c.real << ' ' << c.imaginary << '\n';
}
