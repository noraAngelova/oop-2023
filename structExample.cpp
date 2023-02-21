#include <iostream>

struct Person {
	char name[256];
	unsigned age;
	// вътрешна дефиниция, член-функцията е вградена (inline)
	void print() const {
		std::cout << name << " " << age;
	}
	void printName() const;
};
// външна дефиниция
void Person::printName() const {
	std::cout << name;
}

int main() {
	Person person;
	Person* personPtr = &person;
	std::cin.getline(person.name, 256);
	person.age = 35;

	person.printName();
	std::cout << std::endl;

	person.print();
	std::cout << std::endl;

	personPtr->age = 30;
	personPtr->print();
	return 0;
}
