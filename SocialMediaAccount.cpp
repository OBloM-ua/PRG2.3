#include "SocialMediaAccount.h"

SocialMediaAccount::SocialMediaAccount(string name, shared_ptr<Person> sharedPtr) {
    this->name = name;
    this->score = 0;
    add_person(sharedPtr);
}

void SocialMediaAccount::add_msg(const string str) {
    messages.push_back(str);
}

SocialMediaAccount::~SocialMediaAccount() {

}

bool SocialMediaAccount::add_person(shared_ptr<Person> person) {
    try {
        authorized_persons.push_back(person);
    } catch(exception e){
        return false;
    }
    return true;
}
