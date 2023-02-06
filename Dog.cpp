#include "Dog.h"
#include <bits/stdc++.h>
using namespace std;

Dog::Dog()
{
}

Dog::~Dog()
{
}

void Dog::Input()
{
    cout << setw(113) << "Nhap ten khoa hoc cua cho: ";
    getline(cin >> ws, Binomial_nomenclature);
    Pet::Input();
}

void Dog::Output()
{
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    cout << setw(168) << "|    ID    |        TEN KHOA HOC        |  TUOI  | CHIEU CAO | CAN NANG |     MAU LONG     |  CSTH  |   SO LUONG   |    THANH TIEN    |\n";
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    cout << setw(33) << "|" << setw((10 - Key.length()) / 2) << " " << Key << setw(10 - Key.length() - (10 - Key.length()) / 2) << " "
         << "|" << setw((28 - Binomial_nomenclature.length()) / 2) << " " << Binomial_nomenclature << setw(28 - Binomial_nomenclature.length() - (28 - Binomial_nomenclature.length()) / 2) << " ";
    Pet::Output();
}

void Dog::init1(string id, string TenKH, float Tuoi, float ChieuCao, float CanNang, string MauDa, float ChiSoThuanHoa, int sl)
{
    this->Key = id;

    this->Binomial_nomenclature = TenKH;

    this->Ageold = Tuoi;

    this->Height = ChieuCao;

    this->Weight = CanNang;

    this->Skincolor = MauDa;

    this->Thoroughbred_index = ChiSoThuanHoa;

    this->Nums = sl;
}

Dog *Dog::operator=(Dog *Z)
{
    if (this != Z)
    {
        this->Binomial_nomenclature = Z->Binomial_nomenclature;

        this->Ageold = Z->Ageold;

        this->Height = Z->Height;

        this->Key = Z->Key;

        this->Skincolor = Z->Skincolor;

        this->Thoroughbred_index = Z->Thoroughbred_index;

        this->Weight = Z->Weight;
    }
    return this;
}

long long Dog::Price()
{
    return Pet::Price();
}
