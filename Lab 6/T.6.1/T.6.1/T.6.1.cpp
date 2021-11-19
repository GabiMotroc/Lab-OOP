// T.6.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber {
private:
    double realPart;
    double imaginaryPart;
public:
    ComplexNumber(double re = 0, double im = 0) : realPart(re), imaginaryPart(im) {};
    void setImaginaryPart(double im)
    {
        imaginaryPart = im;
    }
    void setRealPart(double re)
    {
        realPart = re;
    }
    double getImaginaryPart()
    {
        return imaginaryPart;
    }
    double getRealPart()
    {
        return realPart;
    }

};
class Operations {

private:
    ComplexNumber* complex;
public:
    Operations() {};
    Operations(ComplexNumber* complex) :complex(complex) {};

    static double module(double value)
    {
        return (value > 0 ? value : -value);
    }
    static double module(ComplexNumber* number)
    {
        if (number)
        {
            auto im = number->getImaginaryPart();
            auto re = number->getRealPart();
            return sqrt(im * im + re * re);
        }
        else
            throw invalid_argument("cannot perform module one a null complex number");

    }
    double module()
    {
        if (complex)
        {
            auto im = complex->getImaginaryPart();
            auto re = complex->getRealPart();
            return sqrt(im * im + re * re);
        }
        else
            throw invalid_argument("cannot perform module one a null complex number");

    }
};

int main()
{
    auto op = new Operations(new ComplexNumber(5, 5));
    cout << op->module() << '\n';
    cout << Operations::module(-5) << '\n';
    auto nr = new ComplexNumber(5, 5);
    cout << Operations::module(nr);

    delete nr;
}