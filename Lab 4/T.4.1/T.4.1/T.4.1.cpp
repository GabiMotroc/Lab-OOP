// T.4.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person() 
    {
        age = -1;
    }
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
};

class GroupOfFriends
{
private:
    list<Person> friends;
public:
    GroupOfFriends() {}
    GroupOfFriends(GroupOfFriends* groupOfFriends) 
    {
        this->friends = groupOfFriends->friends;
    }
    void AddFriend(Person person)
    {
        friends.push_back(person);
    }

    void ModifyFriend(string key, Person person)
    {
        for (auto it = friends.begin(); it != friends.end(); it++)
        {
            if (it->getName() == key)
            {
                *it = person;
                break;
            }
        }
    }

    void RemoveFriend(Person person)
    {
        for (auto it = friends.begin(); it != friends.end(); it++)
        {
            if (it->getName() == person.getName())
            {
                friends.erase(it);
                break;
            }
        }
    }
    void Display()
    {
        for (Person& person : friends)
        {
            cout << person.getName() << ' ' << person.getAge() << '\n';
        }
    }
};

int main()
{
    GroupOfFriends party;
    party.AddFriend({ "John", 20 });
    party.AddFriend({ "Mathew", 19 });
    Person Alice = Person("Alice", 24);
    party.AddFriend(Alice);
    party.Display();
    cout << '\n';

    party.RemoveFriend(Alice);
    party.ModifyFriend("John", Alice);
    party.Display();
}
