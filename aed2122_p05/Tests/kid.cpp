#include "kid.h"

Kid::Kid(): name(""), age(0), sex('x') {}

Kid::Kid(string nm, unsigned a, char s): name(nm), age(a), sex(s) {}

Kid::Kid(const Kid& k1) {
	this->name = k1.name;
	this->age = k1.age;
    this->sex = k1.sex;
}

string Kid::getName() const {
	return this->name;
}

unsigned Kid::getAge() const {
	return this->age;
}

char Kid::getSex() const {
    return this->sex;
}

bool Kid::operator==(const Kid& k2) const {
	return( this->name == k2.name && this->age == k2.age);
}

string Kid::write() const {
	stringstream oss;
	oss << name << " : " << age;
	return oss.str();
}
