// T.3.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

enum CoursesList { Maths = 0, Geography = 1, Chemistry = 2};

class Student;

class Course
{
private:
	string courseName, courseTeacher;
	list<Student*> students;
public:
	Course() { }
	Course(string courseName, string courseTeacher)
	{
		this->courseName = courseName;
		this->courseTeacher = courseTeacher;
	}
	~Course() { }
	void AddStudent(Student* student)
	{
		students.push_back(student);
	}
	list<Student> getListOfStudents()
	{
		list<Student> result;
		for (list<Student*>::iterator it = students.begin(); it != students.end(); ++it)
		{
			result.push_back(*(*it));
		}
		return result;
	}
};

class Student
{
private:
	string firstName, lastName, groupe;
	list<Course*> courses;
public:
	Student() {}
	Student(string firstName, string lastName)
	{
		this->firstName = firstName;
		this->lastName = lastName;
	}
	~Student()
	{

	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	void AddCourse(Course* course)
	{
		courses.push_back(course);
	}
};

list<Student*> students;
list<Course*> courses;

// first name first
Student* SearchStudentByName(string firstName, string lastName)
{
	for (list<Student*>::iterator it = students.begin(); it != students.end(); ++it)
	{
		if ((*it)->getFirstName() == firstName and (*it)->getLastName() == lastName)
			return (*it);
	}
	return NULL;
}

void EnrollStudent(Student* student, int course)
{
	list<Course*>::iterator it = courses.begin();
	advance(it, course);
	student->AddCourse(*it);
	(*it)->AddStudent(student);
}

void AddStudent()
{
	string firstName, lastName;
	cout << "First name: ";
	cin >> firstName;
	cout << "Last name: ";
	cin >> lastName;
	Student* input = new Student(firstName, lastName);
	students.push_back(input);
}

void DeleteStudent()
{
	string firstName, lastName;
	cout << "First name: \n";
	cin >> firstName;
	cout << "Last name: \n";
	cin >> lastName;
	auto result = SearchStudentByName(firstName, lastName);
	if(result != NULL)
		students.remove(result);
}

void ShowTheNumberOfStudents()
{
	cout << students.size() << '\n';
}

void EnrollStudent()
{
	string firstName, lastName;
	cout << "First name: \n";
	cin >> firstName;
	cout << "Last name: \n";
	cin >> lastName;
	cout << "Course to enroll: \n"
		<< "1. Maths\n"
		<< "2. Geography\n"
		<< "3. Chemistry\n";
	int x;
	cin >> x;
	x--;

	auto result = SearchStudentByName(firstName, lastName);

	if (result == NULL)
	{
		cout << "Student not found\n";
		return;
	}

	if(x == Maths)
		EnrollStudent(result, Maths);
	else if(x == Geography)
		EnrollStudent(result, Geography);
	else if (x == Chemistry)
		EnrollStudent(result, Chemistry);
}

list<Student> ShowStudentInACourse(int course) 
{
	list<Course*>::iterator it = courses.begin();
	advance(it, course);
	auto result = (*it)->getListOfStudents();
	return result;
}

void ShowStudentInACourse()
{
	cout << "Course to enroll: \n"
		<< "1. Maths\n"
		<< "2. Geography\n"
		<< "3. Chemistry\n";
	int x;
	cin >> x;
	list<Student> result = ShowStudentInACourse(x - 1);
	for (list<Student>::iterator it = result.begin(); it != result.end(); ++it)
	{
		cout << (*it).getFirstName() << ' ' << (*it).getLastName() << '\n';
	}
}

void Menu()
{

	int x = 1;
	while (x)
	{
		cout << "1. Add student \n"
			<< "2. Modify student\n"
			<< "3. Delete student\n"
			<< "4. Add course to student\n"
			<< "5. Show the number of students\n"
			<< "6. List the students enrolled in a course\n";
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
			AddStudent();
			break;
		case 2:
			break;
		case 3:
			DeleteStudent();
			break;
		case 4:
			EnrollStudent();
			break;
		case 5:
			ShowTheNumberOfStudents();
			break;
		case 6:
			ShowStudentInACourse();
			break;
		default:
			break;
		}
	}
}

void InitializeCourses()
{
	Course* math = new Course("Maths", "Teacher 1");
	courses.push_back(math);
	Course* geography = new Course("Geography", "Teacher 2");
	courses.push_back(geography);
	Course* chemistry = new Course("Chemistry", "Teacher 3");
	courses.push_back(chemistry);
}

void InitializeStudents()
{
	Student* student1 = new Student("Ion", "Filip");
	students.push_back(student1);
	Student* student2 = new Student("Gabibo", "George");
	students.push_back(student2);
	Student* student3 = new Student("Andreea", "Catalina");
	students.push_back(student3);
}
int main()
{
	InitializeCourses();
	InitializeStudents();
	Menu();
}
