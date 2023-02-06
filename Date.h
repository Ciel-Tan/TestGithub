#ifndef _DATE
#define _DATE
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int ngay;
    int thang;
    int nam;

public:
    Date();
    Date(const int &, const int &, const int &);
    Date(const Date &);
    ~Date();
    int Getngay();
    void Setngay(int);
    int Getthang();
    void Setthang(int);
    int Getnam();
    void Setnam(int);
    static bool check(const int &, const int &, const int &);
    friend istream &operator>>(istream &, Date &);
    friend ostream &operator<<(ostream &, const Date &);
};

#endif