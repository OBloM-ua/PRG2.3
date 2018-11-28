#include <string>
#include <vector>
#include <memory>


using namespace std;

class SocialMediaAccount;

class Person {
private:
    string name;
    //  Nicht  leer.
    vector<shared_ptr<SocialMediaAccount>> media_accounts;
    // Zu Beginn  leer.
public:
    Person(string);

    string get_name() const;

    int add_account(string, int= 1); //  int  Variable  gibt  Accountmodus an.  1ist VipAccount.  0  ist  NormalAccount .
    bool remove_account(int);// Koennte  Account  mit Nummber  int  geloescht  werden
    bool share(shared_ptr<Person>,
               shared_ptr<SocialMediaAccount>);// this  hat SocialMediaAccount ,  Parameter bekommt  SocialMediaAccount  falls  nicht schon  vorhanden.

    std::ostream &print(ostream &) const;

    std::ostream &print_small(ostream &) const;

    const vector<shared_ptr<SocialMediaAccount>> &getaccounts() const;
};




