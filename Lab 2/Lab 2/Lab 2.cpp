// Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <chrono>

template<typename T> void Display(T a)
{
	std::cout << a << '\n';
}

// T.2.1
template<typename T> void Interchange(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

// T.2.2
int roundTo100(float n)
{
	n /= 100;
	return (int)round(n) * 100;
}

int f(float n, bool isRoundedTo100 = false)
{
	if (isRoundedTo100)
		return roundTo100(n);
	return (int) round(n);
}

// T.2.3
struct Student {
	std::string name;
	int grade;
};

Student max(Student a, Student b)
{
	if (a.grade > b.grade)
		return a;
	else
		return b;
}

struct Student2 {
	std::string name;
	int grade;
	bool operator <( Student2 const& rhs) const
	{
		return grade < rhs.grade;
	}

	// T.2.10
	Student2 &operator =(Student2 const& rhs)
	{
		name = rhs.name;
		grade = rhs.grade;
		return *this;
	}
};

// T.2.4
std::string timeToDate(time_t t)
{
	struct tm* tm = new struct tm;
	gmtime_s(tm, &t);
	char date[20];
	strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", tm);
	return std::string(date);
}

std::string timeToString(long long ms)
{
	time_t t = ms / 1000;
	return timeToDate(t);
}

std::string timeToString()
{
	time_t t = time(NULL);
	return timeToDate(t);
}

// T.2.5
int SizeOf(int a)
{
	return sizeof(a);
}

int SizeOf(double a)
{
	return sizeof(a);
}

int SizeOf(char* a)
{
	return strlen(a);
}

// T.2.7
struct nrComplex
{
	double a, b;
};

double module(nrComplex z)
{
	return sqrt(z.a * z.a + z.b * z.b);
}

double module(double a, double b)
{
	return sqrt(a * a + b * b);
}

// T.2.8
template<typename T> T MaximumOf3(T a, T b, T c)
{
	T aux = a;
	if (!(b < a))
		aux = b;
	if (!(c < aux))
		aux = c;
	return aux;
}

// T.2.9
template<typename T> T SumOf2(T a, T b)
{
	return a + b;
}

// T.2.12
struct T212
{
	int age;

	bool operator <(T212 const& rhs) const
	{
		return age < rhs.age;
	}

	bool operator == (T212 const& rhs) const
	{
		return age == rhs.age;
	}
};

struct Cat : T212
{
	std::string name;
	std::string master;
	Cat(std::string name1, std::string master1, int age1)
	{
		name = name;
		master = master1;
		age = age1;
	}
};

struct Person : T212
{
	std::string name;

	Person(std::string name1, int age1)
	{
		name = name;
		age = age1;
	}
};

struct Car : T212
{
	std::string producer;
	std::string licencePlate;

	Car(std::string producer1, std::string licencePlate1, int age1)
	{
		producer = producer1;
		licencePlate = licencePlate1;	
		age = age1;
	}
};

template<typename T, typename S> bool CheckSmaller (T a, S b)
{
	return a < b;
}

template<typename T, typename S> bool CheckSame(T a, S b)
{
	return a == b;
}

int main()
{
	// T.2.1
	std::cout << "\nT.2.1\n";
	int a = 2;
	int b = 5;
	Interchange(a, b);
	std::cout << a << ' ' << b << '\n';

	// T.2.2
	std::cout << "\nT.2.2\n";
	Display(f(2.1f));
	Display(f(1562, true));

	// T.2.3
	std::cout << "\nT.2.3\n";
	Student Ion{ "Ion", 90 };
	Student Robert{ "Robert", 78 };
	Student TopOfHisClass = max(Ion, Robert);
	std::cout << TopOfHisClass.name << ": " << TopOfHisClass.grade << '\n';

	// a second method which i find to be neat
	Student2 Alice{ "Alice", 90 };
	Student2 Mircea{ "Mircea", 78 };
	Student2 TopOfHisClass2 = std::max(Alice, Mircea);
	std::cout << TopOfHisClass2.name << ": " << TopOfHisClass2.grade << '\n';

	// T.2.4
	std::cout << "\nT.2.4\n";
	std::cout << timeToString(1631970174315) << '\n';
	std::cout << timeToString() << '\n';

	// T.2.5
	std::cout << "\nT.2.5\n";
	int a25 = 4;
	double b25 = 2.4;
	char* c25 = new char[12];
	strcpy_s(c25, 5, "test");
	std::cout << SizeOf(a25) << ' ' << SizeOf(b25) << ' ' << SizeOf(c25) << '\n';

	// T.2.7
	std::cout << "\nT.2.7\n";
	nrComplex a27{ 2.3, 4.7 };
	std::cout << module(a27) << ' ' << module(2.3, 4.7) << '\n';

	// T.2.8
	std::cout << "\nT.2.8\n";
	Student2 Oana{ "Oana", 85 };
	std::cout << MaximumOf3(a, b, a25) << ' ' << MaximumOf3(b25, 2.3, 7.0) << ' ' << MaximumOf3(Oana, Alice, Mircea).name << '\n';

	// T.2.9
	std::cout << "\nT.2.9\n";
	std::cout << SumOf2(2, 3) << ' ' << SumOf2(5.1f, 3.0f) << ' ' << SumOf2(9.1, 0.2) << '\n';
	std::cout << "Works for very variable type that has a definded + operator\n";

	// T.2.10
	 std::cout << "\nT.2.10\n";
	// Same function as 2.1
	Interchange(Oana, Alice);
	std::cout << Oana.name << ' ' << Oana.grade << '\n';

	// T.2.12
	std::cout << "\nT.2.12\n";
	Cat gatto( "gatto", "Henry", 12);
	Car car( "VW", "DJ10ABC", 15);
	Person Henry( "Henry", 24 );

	if( CheckSmaller(gatto, Henry))
	std::cout << "The cat is younger than Henry.\n";
	else
		std::cout << "Henry is younger than the cat .\n";

	if(car < Henry)
		std::cout << "The car is younger than Henry.\n";
	else
		std::cout << "Henry is younger than the car .\n";

	if (CheckSame(gatto, Henry))
		std::cout << "The cat, and Henry have the same age.\n";
	else
		std::cout << "The cat, and Henry dont have the same age.\n";

	if (car == Henry)
		std::cout << "The car, and Henry have the same age.\n";
	else
		std::cout << "The car, and Henry dont have the same age.\n";

} 