// T.3.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Student
{
private:
	int grade;
	
public:
	static int currentStudents;
	Student()
	{
		grade = 1;
		currentStudents++;
	}
	Student(int grade)
	{
		this->grade = grade;
		currentStudents++;
	}
	~Student();

	int getNumberOfStudents()
	{
		return currentStudents;
	}

	int getGrade()
	{
		return grade;
	}
	void setGrade(int grade)
	{
		this->grade = grade;
	}
};

int Student::currentStudents;

Student::~Student()
{
	currentStudents--;
}

int main()
{
	Student* ion = new Student();
	Student* robert = new Student(8);
	std::cout << ion->getNumberOfStudents() << ' ' << robert->getNumberOfStudents() << '\n';
	delete ion;
	std::cout << robert->getNumberOfStudents();
}
