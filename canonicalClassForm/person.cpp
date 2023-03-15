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

Person::Person(Person && other) {
	age = other.age;
	firstName = other.firstName;

	other.firstName = nullptr;
	other.age = 0;
}

Person& Person::operator=(Person && other) {
	if (this != &other) {
		age = other.age;

		delete[] firstName;
		firstName = other.firstName;

		other.firstName = nullptr;
		other.age = 0;
	}

	return *this;
}

// Предефиниране на оператори
bool Person::operator<(Person const& other) const {
	return age < other.age;
}

bool Person::operator==(Person const& other) const {
	return (age == other.age) && strcmp(firstName, other.firstName) == 0;
}


void Person::print() const {
	std::cout << firstName << " " << age;
}
