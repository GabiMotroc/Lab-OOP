// T.3.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Car
{
private:
	string color;
	int speed;
public:
	/*add a static car that has no defined color */
	Car()
	{
		speed = 0;
	}
	/*copy a car*/
	Car(Car *car)
	{
		speed = car->speed;
		color = car->getColor();
	}
	/* add a car that is already moving */
	Car(int speed)
	{
		this->speed = speed;
	}

	/*add a car that has a defined color, speed will be 0 as default */
	Car(string color)
	{
		speed = 0;
		this->color = color;
	}

	/* add a car that is already movingand has a defined color*/
	Car(int speed, string color)
	{
		this->speed = speed;
		this->color = color;
	}

	void setColor(string color)
	{
		this->color = color;
	}
	string getColor()
	{
		return color;
	}
	void Accelerate(int a)
	{
		speed += a;
	}
	void Stop()
	{
		speed = 0;
	}
	void Display()
	{
		cout << "This car is traveling at " << speed << "km/s and has the color " << color << '\n';
	}
};

int main()
{
	Car Peugeot = new Car();
	Car Renault = new Car(10, "yellow");
	Car SecondRenault = new Car(Renault); 
	Peugeot.Accelerate(5);

	Peugeot.Display();
	Renault.Display();
	SecondRenault.Display();

}