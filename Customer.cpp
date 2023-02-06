#include <bits/stdc++.h>
#include "Customer.h"

using namespace std;

Customer::Customer(int a, string b, string c, Date d, int e)
{
    this->id = a;
    this->tele = b;
    this->ht = c;
    this->ngaymua = d;
    this->times = e;
}

Customer::~Customer() {}

int Customer::get_times()
{
    return this->times;
}

string Customer::get_ht()
{
    return this->ht;
}

int Customer::get_id()
{
    return this->id;
}

string Customer::get_phone()
{
    return this->tele;
}

Date Customer::get_ngaymua()
{
    return this->ngaymua;
}

void Customer::set_ht(const string &ht)
{
    this->ht = ht;
}

void Customer::set_id(const int &id)
{
    this->id = id;
}

void Customer::set_phone(const string &phone)
{
    this->tele = phone;
}

void Customer::set_times(const int &a)
{
    this->times = a;
}

void Customer::set_ngaymua(const Date &Ngaymua)
{
    this->ngaymua = Ngaymua;
}

void Customer::init(int a, string b, string c, Date d, int t)
{
    this->id = a;
    this->tele = b;
    this->ht = c;
    this->ngaymua = d;
    this->times = t;
}

void Customer::display()
{
    cout << setw(145) << "+----------+----------------+-----------------------------+-----------------+------------+" << endl;
    cout << setw(145) << "|    ID    |       SDT      |          HO VA TEN          |  NGAY MUA HANG  | SO LAN MUA |" << endl;
    cout << setw(145) << "+----------+----------------+-----------------------------+-----------------+------------+" << endl;
    cout << setw(56) << "|" << setw(8) << this->id << setw(3)
         << "|" << setw((16 - this->tele.length()) / 2) << " " << this->tele << setw(17 - this->tele.length() - (16 - this->tele.length()) / 2)
         << "|" << setw((29 - this->ht.length()) / 2) << " " << this->ht << setw(30 - this->ht.length() - (29 - this->ht.length()) / 2)
         << "|" << setw(6) << this->ngaymua << setw(4)
         << "|" << setw(7) << this->times << setw(6)
         << "|" << endl;
    cout << setw(145) << "+----------+----------------+-----------------------------+-----------------+------------+" << endl
         << endl;
}

ifstream &operator>>(ifstream &in, Customer &khach)
{
    in >> khach.ngaymua;
    return in;
}