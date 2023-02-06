#include "NhanVien.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

NhanVien::NhanVien()
{
}

NhanVien::~NhanVien()
{
}

string NhanVien::GetID()
{
    return this->ID;
}

void NhanVien::SetID(const string &ID)
{
    this->ID = ID;
}

string NhanVien::GetName()
{
    return this->Name;
}

void NhanVien::SetName(const string &Name)
{
    this->Name = Name;
}

int NhanVien::GetAge()
{
    return this->Age;
}

void NhanVien::SetAge(const int &Age)
{
    this->Age = Age;
}

string NhanVien::GetGender()
{
    return this->Gender;
}

void NhanVien::SetGender(const string &Gender)
{
    this->Gender = Gender;
}

float NhanVien::GetHeSoLuong()
{
    return this->HeSoLuong;
}

void NhanVien::SetHeSoLuong(const float &HeSoLuong)
{
    this->HeSoLuong = HeSoLuong;
}

float NhanVien::GetLuongCoBan()
{
    return this->LuongCoBan;
}

void NhanVien::SetLuongCoBan(const float &LuongCoBan)
{
    this->LuongCoBan = LuongCoBan;
}

void NhanVien::Input()
{
    cout << setw(108) << "Nhap ho ten nhan vien: ";
    getline(cin >> ws, Name);

    cout << setw(96) << "Nhap tuoi: ";
    cin >> Age;

    cout << setw(101) << "Nhap gioi tinh: ";
    getline(cin >> ws, Gender);

    cout << setw(103) << "Nhap he so luong: ";
    cin >> HeSoLuong;

    cout << setw(104) << "Nhap luong co ban: ";
    cin >> LuongCoBan;
}

void NhanVien::Output()
{
    cout << setw(158) << "+----------+----------------------------+--------+-------------+---------------+----------------+-----------------+\n";
    cout << setw(158) << "|    ID    |          HO VA TEN         |  TUOI  |  GIOI TINH  |  HE SO LUONG  |  LUONG CO BAN  |      LUONG      |\n";
    cout << setw(158) << "+----------+----------------------------+--------+-------------+---------------+----------------+-----------------+\n";
    cout << setw(43) << "|" << setw((10 - ID.length()) / 2) << " " << ID << setw(11 - ID.length() - (10 - ID.length()) / 2)
         << "|" << setw((28 - Name.length()) / 2) << " " << Name << setw(29 - Name.length() - (28 - Name.length()) / 2)
         << "|" << setw(5) << Age << setw(4)
         << "|" << setw((13 - Gender.length()) / 2) << " " << Gender << setw(14 - Gender.length() - (13 - Gender.length()) / 2)
         << "|" << setw(9) << HeSoLuong << setw(7)
         << "|" << setw(12) << (size_t)LuongCoBan << setw(5)
         << "|" << setw(13) << (size_t)Salary() << setw(5)
         << "|" << endl;
    cout << setw(158) << "+----------+----------------------------+--------+-------------+---------------+----------------+-----------------+\n";
    cout << endl;
}

void NhanVien::init(string a, string b, int c, string d, float e, float f)
{
    this->ID = a;

    this->Name = b;

    this->Age = c;

    this->Gender = d;

    this->HeSoLuong = e;

    this->LuongCoBan = f;
}

NhanVien *NhanVien::operator=(NhanVien *Z)
{
    if (this != Z)
    {
        this->ID = Z->ID;

        this->Name = Z->Name;

        this->Age = Z->Age;

        this->Gender = Z->Gender;

        this->HeSoLuong = Z->HeSoLuong;

        this->LuongCoBan = Z->LuongCoBan;
    }
    return this;
}

float NhanVien::Salary()
{
    return HeSoLuong * LuongCoBan;
}
