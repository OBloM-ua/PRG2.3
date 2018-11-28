#include "Person.h"

Person::Person(string name) {
    this->name = name;
}

string Person::get_name() const {
    return name;
}

// int Variable gibt Accountmodus an.1 1ist VipAccount. 0 ist NormalAccount.
int Person::add_account(string str, int modus) {
    if(modus == 0){
        shared_ptr<SocialMediaAccount> p(new NormalAccount(*this));
        media_accounts.push_back(p);
    }
    if (modus == 1){

    }

    return 0;
}

