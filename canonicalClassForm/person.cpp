#define _CRT_SECURE_NO_WARNINGS
#include "person.hpp"
#include <iostream>
#include <cstring>

Person::Person(char const * name, unsigned const& ageData) {
	age = ageData;
  
	firstName = new char[strlen(name) + 1];
	strcpy(firstName, name);
}

Person::~Person() {
	delete [] firstName;
}

Person::Person(Person const& other) {
	age = other.age;

	firstName = new char[strlen(other.firstName) + 1];
	strcpy(firstName, other.firstName);
}

// Връща Person&, за да е възможно верижно извикване на оператора a = b = c
Person& Person::operator=(Person const& other) {
	if (this != &other) {
		age = other.age;

		delete [] firstName;
		firstName = new char[strlen(other.firstName) + 1];
		strcpy(firstName, other.firstName);
	}
	
	return *this;
}

void Person::print() const {
	std::cout << firstName << " " << age;
}
