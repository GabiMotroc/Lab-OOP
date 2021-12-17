// T 9.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Shape
{
public:
	virtual void computeArea() = 0;
};

class Circle : public Shape
{
public:
	double radius;
	Circle(const double radius)
	{
		this->radius = radius;
	}
	void computeArea()
	{
		cout << 3.14 * this->radius * this->radius << endl;
	}
};

class Rectangle : public Shape
{
public:
	double width, length;

	Rectangle(const double width, const double length)
	{
		this->width = width;
		this->length = length;
	}

	void computeArea()
	{
		cout << this->width * this->length << endl;
	}
};

class Square : public Shape
{
public:
	double side;

	Square(const double side)
	{
		this->side = side;
	}

	void computeArea()
	{
		cout << this->side * this->side << endl;
	}
};

class Drawing
{
public:
	Shape* pShape;

	Drawing(Shape* pShape)
	{
		this->pShape = pShape;
	}

	void getArea() const
	{
		pShape->computeArea();
	}
};

int main()
{
	auto d = new Drawing(new Rectangle(2, 3));
	d->getArea();
	auto e = new Drawing(new Circle(1));
	e->getArea();
	auto f = new Drawing(new Square(5));
	f->getArea();
}