#ifndef _STUDENT_HPP
#define _STUDENT_HPP
#define _CRT_SECURE_NO_WARNINGS

#include "person.hpp"
#include <iostream>
#include <cstring>

class Student : protected Person {
protected:
	char* fn;
public:
	Student() {
		fn = new char[1];
		strcpy(fn, "\0");
	}
	Student(char const* name, unsigned const& age, char const* fnStr) : Person(name, age) {
		fn = new char[strlen(fnStr) + 1];
		strcpy(fn, fnStr);
	}
	
	~Student() {
		delete[] fn;
	}
	
	Student(Student const& other) : Person(other) {
		fn = new char[strlen(other.fn) + 1];
		strcpy(fn, other.fn);
	}

	Student& operator=(Student const& other) {
		if (this != &other) {
			Person::operator=(other);
			delete[] fn;

			fn = new char[strlen(other.fn) + 1];
			strcpy(fn, other.fn);
		}

		return *this;
	}

	void print() const {
		Person::print();
		std::cout << " " << fn;
	}
};

#endif
