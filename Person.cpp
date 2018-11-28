#include "Person.h"

Person::Person(string name) {
    this->name = name;
}

string Person::get_name() const {
    return name;
}

int Person::add_account(string, int) {
    return 0;
}

