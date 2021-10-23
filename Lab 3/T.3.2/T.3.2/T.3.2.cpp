// T.3.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Kitty
{
private:
	int age;
	string name;
public:
	Kitty()
	{
		age = 0;
	}
	Kitty(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	Kitty(Kitty* kitty)
	{
		this->age = kitty->age;
		this->name = kitty->name;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{     
		return name;
	}

	void display()
	{
		cout << name << ' ' << age << '\n';
	}
};

int main()
{
	Kitty tom;
	tom.setAge(3);
	tom.setName("Tom");
	tom.display();

	Kitty cat = new Kitty(12, "alfred");
	cat.display();

	Kitty cat2 = new Kitty(cat);
	cat2.display();
}
