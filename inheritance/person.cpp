#define _CRT_SECURE_NO_WARNINGS
#include "person.hpp"
#include <iostream>
#include <cstring>

unsigned Person::counter = 1;

void Person::copy(char const* name) {
	firstName = new char[strlen(name) + 1];
	strcpy(firstName, name);
}

void Person::print() const {
	std::cout << firstName << " " << age;
}

Person::Person(char const * name, unsigned const& ageData) {
	age = ageData;
	copy(name);

	id = counter;
	counter++;
}

Person::~Person() {
	delete [] firstName;
}

Person::Person(Person const& other) {
	age = other.age;
	copy(other.firstName);

	id = counter;
	counter++;
}

Person& Person::operator=(Person const& other) {
	if (this != &other) {
		age = other.age;

		delete [] firstName;
		copy(other.firstName);
	}
	
	return *this;
}

Person::Person(Person && other) {
	age = other.age;
	firstName = other.firstName;

	id = counter;
	counter++;

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

std::istream& operator>>(std::istream& is, Person& p) {
	unsigned capacity = 1;
	is >> capacity;

	delete[] p.firstName;
	p.firstName = new char[capacity];
	is.getline(p.firstName, capacity);
	is >> p.age;

	return is;
}
