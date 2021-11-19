// T.6.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<cmath>
#include <iostream>
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
    friend ostream& operator<<(ostream& os, const ComplexNumber number)
    {
        os << "(" << number.realPart << "," << number.imaginaryPart << ")";
        return os;
    }
    double operator~()
    {
        return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
    }
    ComplexNumber operator*(ComplexNumber other)
    {
        ComplexNumber c;
        double re = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        double im = realPart * other.imaginaryPart + imaginaryPart * other.realPart;
        c.setRealPart(re);
        c.setImaginaryPart(im);
        return c;
    }
    ComplexNumber operator+(ComplexNumber other)
    {
        ComplexNumber c;
        double re = realPart + other.realPart;
        double im = other.imaginaryPart + imaginaryPart;
        c.setRealPart(re);
        c.setImaginaryPart(im);
        return c;
    }
    ComplexNumber operator^(int p)
    {
        ComplexNumber prod(1, 0);
        ComplexNumber a = (*this);
        while (p)
        {
            if (p & 1)
                prod = prod * a;
            a = a * a;
            p >>= 1;
        }
        return prod;
    }
};


int main()
{
    ComplexNumber c(0, 1);
    cout << ~c << '\n';
    cout << (c ^ 4) << '\n';
    cout << c + c;
}