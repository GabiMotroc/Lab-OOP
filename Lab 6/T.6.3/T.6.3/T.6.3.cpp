// T.6.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
    friend ostream& operator<<(ostream& os, const ComplexNumber* number)
    {
        os << "(" << number->realPart << "," << number->imaginaryPart << ")";
        return os;
    }
};
class Operations {

private:
    ComplexNumber* complex1;
    ComplexNumber* complex2;
public:
    Operations() {};
    Operations(ComplexNumber* complex1, ComplexNumber* complex2) :complex1(complex1), complex2(complex2) {};

    static double sum(double lhs, double rhs)
    {
        return lhs + rhs;
    }
    static ComplexNumber* sum(ComplexNumber* lhs, ComplexNumber* rhs)
    {
        if (lhs && rhs)
        {
            return new ComplexNumber(lhs->getRealPart() + rhs->getRealPart(), lhs->getImaginaryPart() + rhs->getImaginaryPart());
        }
        else
            throw invalid_argument("cannot perform module one a null complex number");

    }
    ComplexNumber* sum()
    {
        if (complex1 && complex2)
        {
            return new ComplexNumber(complex1->getRealPart() + complex2->getRealPart(), complex1->getImaginaryPart() + complex2->getImaginaryPart());
        }
        else
            throw invalid_argument("cannot perform module one a null complex number");

    }
};

int main()
{
    auto c1 = new ComplexNumber(5, 5);
    auto op = new Operations(c1, c1);
    cout << op->sum() << '\n';
    cout << Operations::sum(c1, c1) << '\n';
    cout << Operations::sum(2, 3);



}