// T 9.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape
{
public:
	virtual double computeArea() = 0;
};

class Circle : public Shape
{
public:
	double radius;

	Circle(const double radius)
	{
		this->radius = radius;
	}

	double computeArea()
	{
		return 3.14 * this->radius * this->radius;
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
	double computeArea()
	{
		return this->width * this->length;
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
	double computeArea()
	{
		return this->side * this->side;
	}
};

class Triangle : public Shape
{
public:
	double side1;
	double side2;
	double side3;
	double p = 0;

	Triangle(const double side1, const double side2, const double side3)
	{
		this->side1 = side1;
		this->side2 = side2;
		this->side3 = side3;
	}

	double computeArea()
	{
		p = (side1 + side2 + side3) / 2;
		return sqrt(p * (p - side1) * (p - side2) * (p - side3));
	}
};

int main()
{
	vector<Shape*>shapes;
	shapes.push_back(new Circle(3));
	shapes.push_back(new Rectangle(2, 3));
	shapes.push_back(new Square(2));
	shapes.push_back(new Triangle(4, 4, 4));

	double result = 0;

	for (const auto element : shapes) 
	{
		result += element->computeArea();
	}

	cout << result;
}