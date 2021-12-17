// T 9.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Vehicle
{
public:
	virtual void start() = 0;
};

class Rocket : public Vehicle
{
private:
	string name_;

public:
	Rocket(const string& name)
	{
		this->name_ = name;
	}
	string getName() const
	{
		return this->name_;
	}
	void start()
	{
		cout << "start " << this->getName() << " rocket" << endl;
	}
};

class Car : public Vehicle
{
private:
	string name;

public:
	Car(const string& name)
	{
		this->name = name;
	}
	string getName() const
	{
		return this->name;
	}
	void start()
	{
		cout << "start " << this->getName() << " car" << endl;
	}
};
int main()
{
	vector <Vehicle*>vehicule;
	vehicule.push_back(new Car("yellow"));
	vehicule.push_back(new Rocket("Sputnik"));
	vehicule.push_back(new Car("Renault"));

	for (const auto element : vehicule) 
	{
		element->start();
	}
}