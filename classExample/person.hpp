#ifndef _PERSON_HPP
#define _PERSON_HPP

class Person {
private:
	char name[256];
	unsigned age;
public:
	void print() const;
};

#endif
