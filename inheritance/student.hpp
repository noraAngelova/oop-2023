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
	// В класът има динамично заделяне на памет и е нужна реализация на канонично представяне
	Student() {
		fn = new char[1];
		strcpy(fn, "\0");
	}
	// Конструктор с пареметри - трябва да инициализира собсвените и наследените член-данни
	// Обръща се към конструкторите на базовите класове в инициализиращия си списък
	// В инициализиращия списък следва да се инициализират и всички член-данни от тип дефиниран от нас клас, ако такива има
	Student(char const* name, unsigned const& age, char const* fnStr) : Person(name, age) {
		fn = new char[strlen(fnStr) + 1];
		strcpy(fn, fnStr);
	}
	// Деструктор - изтрива само собствените член-данни
	~Student() {
		delete[] fn;
	}

	// Копиращ конструктор - има инициализиращ списък и извиква конструкторите на базовите класове и член-данните от тип дефиниран от нас клас.
	Student(Student const& other) : Person(other) {
		fn = new char[strlen(other.fn) + 1];
		strcpy(fn, other.fn);
	}

	// Оператор за присвояване - НЯМА инициализиращ списък, инициализацията на наследените член-данни става чрез извикване на Person::operator= в тялото
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
