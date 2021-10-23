// T.3.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	int grade;
public:
	Student(string name, int grade)
	{
		this->name = name;
		this->grade = grade;
	}

	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
	void setGrade(int grade)
	{
		this->grade = grade;
	}
	int getGrade()
	{
		return grade;
	}


};

int main()
{
	Student Ion("Ion", 8);
	Student *Robert = new Student("Robert", 9);
	cout << Ion.getName() << ' ' << Ion.getGrade() << '\n';
	cout << Robert->getName() << ' ' << Robert->getGrade() << '\n';
}
