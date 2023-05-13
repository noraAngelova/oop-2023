#ifndef _TEACHER_HPP
#define _TEACHER_HPP
#define _CRT_SECURE_NO_WARNINGS

#include "person.hpp"
#include <iostream>
#include <cstring>

class Teacher : public Person {
protected:
	unsigned salary;
public:
  // Няма динамично заделяне на памет и различно поведение при копиране => не е нужна реализация на канонично представяне
  // Конструктор без параметри (може и да не се реализира) 
  Teacher() {
		salary = 0;
	}
  // Конструктор с параметри - извиква конструкторите на базовите класове И на член-данните от тип име на клас, ако има такива
	Teacher(char const* name, unsigned const& age, unsigned const& salary) : Person(name, age), salary(salary) {}

  // Метод за извеждане - тъй като методите в базовия и производния клас имат един и същ прототип, използваме Person::print, за да достъпим метода от основния клас
	void print() const {
		Person::print();
		std::cout << " " << salary;
	}
};
#endif
