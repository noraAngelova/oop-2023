#include "person.hpp"
#include <iostream>

void Person::print() const {
	std::cout << name << " " << age;
}
