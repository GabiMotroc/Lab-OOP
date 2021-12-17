// T 9.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

class TestAreaSum
{
private:
	vector<Shape*>shapes_;
	double area1_;
	double area2_;
	double area3_;

public:
	TestAreaSum(const vector<Shape*>& shapes, const double area1, const double area2, const double area3)
	{
		this->shapes_ = shapes;
		this->area1_ = area1;
		this->area2_ = area2;
		this->area3_ = area3;
	}

	bool isAreaSumCorrect()
	{
		double result = 0;

		for (const auto element : shapes_) 
		{
			result += element->computeArea();
		}

		if (this->area1_ + this->area2_ + this->area3_ == result)
			return true;
		return false;
	}
};

int main()
{
	vector<Shape*>shapes;
	shapes.push_back(new Circle(5));
	shapes.push_back(new Square(2));
	shapes.push_back(new Triangle(3, 4, 5));

	double result = 0;
	for (const auto element : shapes) {
		result += element->computeArea();
	}
	cout << result << endl;

	auto testArea = new TestAreaSum(shapes, 78.5, 4, 6);
	cout << testArea->isAreaSumCorrect();
}