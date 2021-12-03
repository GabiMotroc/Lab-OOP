// T7.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>

using namespace std;

class Hummer {
	class Wheel {
		int size;
		string tire;
		string rim;
		int studs;
	public:
		Wheel() {};
		Wheel(int sz, string tire, string rim, int studs) :size(sz), tire(tire), rim(rim), studs(studs) {};
	};
	vector<Wheel> wheels;
public:
	Hummer()
	{
		Wheel w(rand() % 20, "Michelin", "Chrome", rand() % 20);
		wheels.resize(4, w);

	};
	void removeWheel(int nrWheel)
	{
		if (nrWheel >= wheels.size())
			cout << "Cannot remove that wheel!";
		else
		{
			wheels.erase(wheels.begin() + nrWheel - 1);
			cout << "Zip zip zip zip\n Wheel removed!\n";

		}
	}
	void replaceWheel(int nrWheel, int sz, string tr, string rm, int stds)
	{
		if (nrWheel >= wheels.size())
		{
			cout << "Cannot remove that wheel!\n";
			return;
		}
		Wheel w(sz, tr, rm, stds);
		wheels[nrWheel] = w;
		cout << "Wheel " << nrWheel << " Replaced\n";
	}
};

class Carriage {
	class Wheel {
		int size;
		string tire;
		int studs;
	public:
		Wheel() {};
		Wheel(int sz, string tire, int studs) :size(sz), tire(tire), studs(studs) {};
	};
	vector<Wheel> wheels;
public:
	Carriage()
	{
		Wheel w(rand() % 20, "Wooden", rand() % 20);
		wheels.resize(4, w);

	};
	void removeWheel(int nrWheel)
	{
		if (nrWheel >= wheels.size())
			cout << "Cannot remove that wheel!\n";
		else
		{
			wheels.erase(wheels.begin() + nrWheel - 1);
			cout << "Screw Screw Screw Screw\n Wheel removed!\n";

		}
	}
	void replaceWheel(int nrWheel, int sz, string tr, int stds)
	{
		if (nrWheel >= wheels.size())
		{
			cout << "Cannot remove that wheel!\n";
			return;
		}
		Wheel w(sz, tr, stds);
		cout << "Wheel " << nrWheel << " Replaced\n";
		wheels[nrWheel] = w;
	}
};

int main()
{
	auto h = new Hummer();
	auto c = new Carriage();

	h->removeWheel(1);
	c->removeWheel(1);
	cout << "\n\n\n";
	h->replaceWheel(2, 1, "", "", 1);
	c->replaceWheel(10, 1, "", 1);
}