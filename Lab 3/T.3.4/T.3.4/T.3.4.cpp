// T.3.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
	string name;
	int grade;
public:
	Student()
	{
		grade = 0;
	}
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

	bool operator <(Student const& rhs) const
	{
		return grade < rhs.grade;
	}
};

int main()
{
	vector<Student> classOf20;
	Student Ion("Ion", 8);
	Student Robert("Robert", 9);

	classOf20.push_back(Ion);
	classOf20.push_back(Robert);
	classOf20.push_back({ "Maria", 10 });

	Student topOfHisClass;
	for (Student student : classOf20)
	{
		if (topOfHisClass < student)
			topOfHisClass = student;
	}

	cout << topOfHisClass.getName();

}
