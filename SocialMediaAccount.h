
#include "Person.h"

using namespace std;

class SocialMediaAccount {
private:
    constexpr static size_t message_limit{100};

    int score;// Startet auf 0.

    string name;// Nicht  leer

    int accountnumber;// Einzigartig.  Tip: Fortlaufende Nummer....
    vector<weak_ptr<Person>> authorized_persons;

    // Im  Konstruktor  befuellt .

    vector<string> messages;

    //  Startet  leer
    void add_msg(const string);

public:
    SocialMediaAccount(string, shared_ptr<Person>);

    ~SocialMediaAccount();

    bool add_person(shared_ptr<Person>);

    bool clear_weak_ptr();//true falls weak_ptr entfernt wurden, entfernt ”dangling”  weak_ptr
    void clear_messages();

    virtual int calc_score(string) = 0;

    void writemsg(shared_ptr<SocialMediaAccount>, string);// Error  falls Limit erreicht.
    // write msg  erhoeht  score .  Wert von  calc score (string)  ermittelt




    size_t size() const;

    //  Anzahl  von  Nachrichten
    int get_accountnumber() const;

    virtual ostream &print(ostream &) const;

    ostream &print_small(ostream &) const;

};

class VipAccount: public SocialMediaAccount{
public:
    VipAccount(string, shared_ptr<Person>);//Soll  nach dem  urspruenglichem print noch”(VIP)”ausgeben. Leerzeichen beachten.
    ostream& print(ostream&) const; //Liefert den Wert (10 + Laenge des Strings)% 20
    int calc_score(string);
};

class NormalAccount: public SocialMediaAccount{
public:
    NormalAccount(string, shared_ptr<Person>);
    ostream& print(ostream&) const;
    int calc_score(string);  //Liefert den Wert (5 + Laenge des Strings)%10
};