// T.3.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Student
{
private:
	int grade;
	string name;

	Student()
	{
		grade = 8;
	}

public:
	Student* generateStudent()
	{
		return (new Student());
	}
};

int main()
{
	Student* ion = NULL;
	ion = ion->generateStudent();
}
