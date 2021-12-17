// T 9.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Animal
{
public:
	virtual string getName() = 0;
	virtual void chase(Animal* animal) = 0;
};

class Mouse : public Animal
{
private:
	string name_;

public:
	Mouse(const string& name)
	{
		this->name_ = name;
	}

	string getName()
	{
		return this->name_ + " as " + typeid(this).name();
	}

	void chase(Animal* animal)
	{
		cout << "I am chasing " + animal->getName() + "(I am :)" + this->getName() << endl;
	}
};

class Cat : public Animal
{
private:
	string name_;

public:
	Cat(const string& name)
	{
		this->name_ = name;
	}

	string getName()
	{
		return this->name_ + " as " + typeid(this).name();
	}

	void chase(Animal* animal)
	{
		cout << "I am chasing " + animal->getName() + "(I am : )" + this->getName() << endl;
	}
};

class Dog : public Animal
{
private:
	string name_;

public:
	Dog(const string name)
	{
		this->name_ = name;
	}

	string getName()
	{
		return this->name_ + " as " + typeid(this).name();
	}

	void chase(Animal* animal)
	{
		cout << "I am chasing " + animal->getName() + "(I am :)" + this->getName() << endl;
	}
};

int main()
{
	vector<Animal*> chasingList;

	chasingList.push_back(new Dog("Rex"));
	chasingList.push_back(new Cat("Max"));
	chasingList.push_back(new Mouse("Sobo"));
	chasingList.push_back(new Cat("Rex 2"));
	chasingList.push_back(new Dog("Pichi"));

	for (int index = 0; index < chasingList.size() - 1; index++) 
	{
		chasingList.at(index)->chase(chasingList.at(index + 1));
	}

	return(0);
}