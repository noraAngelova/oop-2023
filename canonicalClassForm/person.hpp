#ifndef _PERSON_HPP
#define _PERSON_HPP

class Person {
private:
    // Използва се указател, тъй като името е с произволна дължина
    // Ако в условието е посочена максимална дължина (256), може да се използва следната декларация char firstName[256] и не е необходимо динамично заделяне на памет
	char * firstName; 
	unsigned age;
public:
    // Ако стойността по подразбиране на параметъра name е nullptr, трябва да се внимава с обработката и копирането на стойността
	Person(char const * name = "\0", unsigned const & ageData = 0);
	Person(Person const & other);
	~Person();
	Person& operator=(Person const& other);

	// Move семантика
	Person(Person && other);
	Person& operator=(Person && other);

	void print() const;

	bool operator<(Person const& other) const;
	bool operator==(Person const& other) const;
};

#endif
