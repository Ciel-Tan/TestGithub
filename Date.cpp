#include "Date.h"
#include <iomanip>

Date::Date()
{
    this->ngay = 0;
    this->thang = 0;
    this->nam = 0;
}

Date::Date(const int &ngay, const int &thang, const int &nam)
{
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

Date::Date(const Date &date)
{
    this->ngay = date.ngay;
    this->thang = date.thang;
    this->nam = date.nam;
}

Date::~Date()
{
}

int Date::Getngay()
{
    return this->ngay = ngay;
}

void Date::Setngay(int Ngay)
{
    this->ngay = Ngay;
}

int Date::Getthang()
{
    return this->thang = thang;
}

void Date::Setthang(int Thang)
{
    this->thang = Thang;
}

int Date::Getnam()
{
    return this->nam = nam;
}

void Date::Setnam(int Nam)
{
    this->nam = Nam;
}

bool day31(const int &day)
{
    return (day > 0 && day <= 31);
}

bool day30(const int &day)
{
    return (day > 0 && day <= 30);
}

bool Date::check(const int &ngay, const int &thang, const int &nam)
{
    if (nam < 1950 || nam >= 3000)
        return false;
    else
    {
        switch (thang)
        {
        case 1:
            if (day31(ngay))
                return true;
            break;

        case 3:
            if (day31(ngay))
                return true;
            break;

        case 5:
            if (day31(ngay))
                return true;
            break;

        case 7:
            if (day31(ngay))
                return true;
            break;

        case 8:
            if (day31(ngay))
                return true;
            break;

        case 10:
            if (day31(ngay))
                return true;
            break;

        case 12:
            if (day31(ngay))
                return true;
            break;

        case 4:
            if (day30(ngay))
                return true;
            break;

        case 6:
            if (day30(ngay))
                return true;
            break;

        case 9:
            if (day30(ngay))
                return true;
            break;

        case 11:
            if (day30(ngay))
                return true;
            break;

        case 2:
            if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
            {
                if (ngay > 0 || ngay <= 28)
                    return true;
            }
            else
            {
                if (ngay > 0 || ngay <= 29)
                    return true;
            }
            break;
        }
        return false;
    }
}

istream &operator>>(istream &in, Date &day)
{
    while (true)
    {
        cout << endl
             << endl;
        cout << setw(114) << "==== NHAP NGAY MUA HANG ====" << endl;
        cout << setw(112) << "Ngay          ||          ";
        in >> day.ngay;

        cout << setw(112) << "Thang         ||          ";
        in >> day.thang;

        cout << setw(110) << "Nam           ||        ";
        in >> day.nam;

        if (Date::check(day.ngay, day.thang, day.nam) == true)
            break;
        else
        {
            cout << endl
                 << endl;
            cout << setw(115) << "Ngay vua nhap khong hop le!!!!" << endl
                 << endl;
            cout << setw(84) << " ";
            system("pause");
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Date &day)
{
    if (day.ngay > 0 && day.ngay < 10)
    {
        out << setw(5) << "0" << day.ngay;
    }
    else
        out << day.ngay;
    out << "/";
    if (day.thang > 0 && day.thang < 10)
    {
        out << "0" << day.thang;
    }
    else
        out << day.thang;
    out << "/" << day.nam;

    return out;
}