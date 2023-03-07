#include "person.hpp"
#include <iostream>

int main() {
  // Създава обект с конструктоп по подразбиране
	Person p;
	p.print();
	std::cout << std::endl;
	
  // Създава обект с конструктор за копиране
	Person p2 = p;
	p2.print();
	std::cout << std::endl;

  // Създава обект с конструктор с два параметъра
	Person p3("Ivan", 23);

  // Извършва присвояване между два създадени обекта чрез оператора за присвояване
	p2 = p3;
	p2.print();

	return 0;
}
