// T7.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>

using namespace std;

class Car
{
	string brand;
	string color;
public:
	Car() : brand(""), color("") {};
	Car(string brand, string color) :brand(brand), color(color) {};

	friend ostream& operator<<(ostream& os, const Car& c) {
		cout << " [ " << c.brand << " , " << c.color << " ] ";
		return os;
	}
	void setBrand(string b)
	{
		brand = b;
	}
	void setColor(string c)
	{
		color = c;
	}
};

class Driver
{
	string name;
	int age;
public:
	Driver() : age(0), name("") {};
	Driver(string name, int age) :name(name), age(age) {};
	friend ostream& operator<<(ostream& os, const Driver& d) {
		cout << " [ " << d.name << " , " << d.age << " ] ";
		return os;
	}
	void setAge(int a)
	{
		age = a;
	}
	void setName(string nm)
	{
		name = nm;
	}
};

class CarDriverOneToOne
{
public:
	vector<pair<Car, Driver>> car_driver;
	void addRelation(Car c, Driver d)
	{
		auto relation = make_pair(c, d);
		car_driver.push_back(relation);

	}
	void deleteRelation(int relationId)
	{
		car_driver.erase(car_driver.begin() + relationId);
	}
	void modifyCar(int relationId)
	{
		cout << "Modifying relation : " << relationId << " car...\n";
		cout << "   1. Change brand\n";
		cout << "   2. Change color\n";
		cout << "   3. Change both\n";
		int op; cin >> op;
		string brand, color;
		if (op == 1)
		{
			cin >> brand;
			car_driver[relationId].first.setBrand(brand);
		}
		if (op == 2)
		{
			cin >> color;
			car_driver[relationId].first.setColor(color);
		}
		if (op == 3)
		{
			cin >> color >> brand;
			car_driver[relationId].first.setColor(color);
			car_driver[relationId].first.setBrand(brand);
		}
	}
	void modifyDriver(int relationId)
	{
		cout << "Modifying relation : " << relationId << " driver...\n";
		cout << "   1. Change name\n";
		cout << "   2. Change age\n";
		cout << "   3. Change both\n";
		int op; cin >> op;
		int age; string name;
		if (op == 1)
		{
			cin >> name;
			car_driver[relationId].second.setName(name);
		}
		if (op == 2)
		{
			cin >> age;
			car_driver[relationId].second.setAge(age);
		}
		if (op == 3)
		{
			cin >> name >> age;
			car_driver[relationId].second.setAge(age);
			car_driver[relationId].second.setName(name);
		}
	}
	void displayRelations()
	{
		int i = 0;
		for (auto it : car_driver)
		{
			auto car = it.first;
			auto driver = it.second;
			cout << (i++) << ": " << car << "<->" << driver << '\n';

		}
	}
};

int main()
{
	Car c1("opel", "verde"), c2("audi", "negru");
	Driver d1("John", 20), d2("Mihai", 20);
	auto table = new CarDriverOneToOne();
	table->addRelation(c1, d1);
	table->addRelation(c2, d2);

	table->displayRelations();
	table->modifyCar(0);
	table->displayRelations();
	table->modifyDriver(1);
	table->displayRelations();
	table->deleteRelation(0);
	cout << "After deletion:\n";
	table->displayRelations();
}
