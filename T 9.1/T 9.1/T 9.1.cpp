// T 9.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
	virtual ~Shape() = default;
	virtual void draw() = 0; // we define the general behavior
};

class Circle : public Shape
{
public:
	void draw()
	{
		cout << "circle\n";
	} // we specify the behavior for this shape
};

class Triangle : public Shape
{
public:
	void draw()
	{
		cout << "triangle\n";
	} // we specify the behavior for this shape
};

class Drawing
{
public:
	Shape* pShape;

	Drawing(Shape* pShape)
	{
		this->pShape = pShape;
	}
	void drawShape()
	{
		pShape->draw();
	}
};

int main()
{
	auto d = new Drawing(new Triangle());
	d->drawShape();

	auto e = new Drawing(new Circle());
	e->drawShape();
}
