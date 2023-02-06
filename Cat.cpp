#include "Cat.h"
#include <bits/stdc++.h>
using namespace std;

Cat::Cat()
{
}

Cat::~Cat()
{
}

void Cat::Input()
{
    cout << setw(113) << "Nhap ten khoa hoc cua meo: ";
    getline(cin >> ws, Binomial_nomenclature);
    Pet::Input();
}

void Cat::Output()
{
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    cout << setw(168) << "|    ID    |        TEN KHOA HOC        |  TUOI  | CHIEU CAO | CAN NANG |     MAU LONG     |  CSTH  |   SO LUONG   |    THANH TIEN    |\n";
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    cout << setw(33) << "|" << setw((10 - Key.length()) / 2) << " " << Key << setw(10 - Key.length() - (10 - Key.length()) / 2) << " "
         << "|" << setw((28 - Binomial_nomenclature.length()) / 2) << " " << Binomial_nomenclature << setw(28 - Binomial_nomenclature.length() - (28 - Binomial_nomenclature.length()) / 2) << " ";
    Pet::Output();
}

void Cat::init1(string id, string TenKH, float Tuoi, float ChieuCao, float CanNang, string MauDa, float ChiSoThuanHoa, int sl)
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

Cat *Cat::operator=(Cat *Z)
{
    if (this != Z)
    {
        this->Key = Z->Key;

        this->Binomial_nomenclature = Z->Binomial_nomenclature;

        this->Ageold = Z->Ageold;

        this->Height = Z->Height;

        this->Weight = Z->Weight;

        this->Thoroughbred_index = Z->Thoroughbred_index;

        this->Skincolor = Z->Skincolor;
    }
    return this;
}

long long Cat::Price()
{
    return Pet::Price();
}
