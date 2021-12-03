// T7.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>

using namespace std;

class Group {

	class Student {
	public:
		string fullname;
		int age;
		float avg;
		Student() :fullname(""), age(0), avg(0) { };
		Student(string fn, int age, float avg) : fullname(fn), age(age), avg(avg) {};
	};

	vector<Student> studentList;

public:
	void displayStudentList() {
		cout << "{";

		for (auto it : studentList)
		{
			cout << "{";
			cout << "fullName: " << it.fullname << ", ";
			cout << "age: " << it.age << ", ";
			cout << "avg: " << it.avg;
			cout << "}, ";
		}

		cout << "}";
	}
	void addStudent(string fn, int age, int avg) {
		Student s(fn, age, avg);
		studentList.push_back(s);
	}
};


int main()
{
	auto g = new Group();
	g->addStudent("John", 9, 9);
	g->addStudent("Mihai", 14, 10);
	g->displayStudentList();
}