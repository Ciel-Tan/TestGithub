#ifndef _CUSTOMER
#define _CUSTOMER
#include <string>
#include "Date.h"

using std::string;

class Customer
{
protected:
    int id;
    string ht;
    string tele;
    Date ngaymua;
    int times;

public:
    int catbuy[100] = {};
    int dogbuy[100] = {};
    int ncat = 0;
    int ndog = 0;

public:
    Customer(int = 0, string = "", string = "", Date = Date(-1, -1, -1), int = 0);
    ~Customer();

    int get_id();
    string get_ht();
    string get_phone();
    int get_times();
    Date get_ngaymua();

    void set_times(const int &);
    void set_id(const int &);
    void set_ht(const string &);
    void set_phone(const string &);
    void set_ngaymua(const Date &);

    void init(int, string, string, Date, int);
    void display();
    friend ifstream &operator>>(ifstream &, Customer &);
};

#endif