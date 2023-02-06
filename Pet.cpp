#include <bits/stdc++.h>
#include "Pet.h"
#include <fstream>
using namespace std;
// using std::ifstream;

Pet::Pet(string Key, string TenKH, float Tuoi, float ChieuCao, float CanNang, string MauDa, float ChiSoThuanHoa, int sl)
{
    this->Key = Key;
    this->Binomial_nomenclature = TenKH;
    this->Ageold = Tuoi;
    this->Height = ChieuCao;
    this->Weight = CanNang;
    this->Skincolor = MauDa;
    this->Thoroughbred_index = ChiSoThuanHoa;
    this->Nums = sl;
}

Pet::~Pet()
{
}

string Pet::getKey()
{
    return this->Key;
}

void Pet::setKey(string Key)
{
    this->Key = Key;
}

string Pet::GetBinomial_nomenclature()
{
    return Binomial_nomenclature;
}
void Pet::SetBinomial_nomenclature(string tenKH)
{
    Binomial_nomenclature = tenKH;
}
float Pet::GetAgeold()
{
    return Ageold;
}
void Pet::SetAgeold(float Tuoi)
{
    Ageold = Tuoi;
}
float Pet::GetHeight()
{
    return Height;
}
void Pet::SetHeight(float ChieuCao)
{
    Height = ChieuCao;
}
float Pet::GetWeight()
{
    return Weight;
}
void Pet::SetWeight(float CanNang)
{
    Weight = CanNang;
}
string Pet::GetSkincolor()
{
    return Skincolor;
}
void Pet::SetSkincolor(string MauDa)
{
    Skincolor = MauDa;
}
float Pet::GetThoroughbred_index()
{
    return Thoroughbred_index;
}
void Pet::SetThoroughbred_index(float ChiSoThuanHoa)
{
    Thoroughbred_index = ChiSoThuanHoa;
}

void Pet::Input()
{
    cout << setw(97) << "Nhap tuoi: ";
    cin >> Ageold;

    cout << setw(102) << "Nhap chieu cao: ";
    cin >> Height;

    cout << setw(101) << "Nhap can nang: ";
    cin >> Weight;

    cout << setw(101) << "Nhap mau long: ";
    getline(cin >> ws, Skincolor);

    cout << setw(109) << "Nhap chi so thuan hoa: ";
    cin >> Thoroughbred_index;

    cout << setw(114) << "Nhap so luong co trong kho: ";
    cin >> Nums;
}

void Pet::Output()
{
    cout << "|" << setw(5) << Ageold << setw(4)
         << "|" << setw(7) << Height << setw(5)
         << "|" << setw(7) << Weight << setw(4)
         << "|" << setw((18 - Skincolor.length()) / 2) << " " << Skincolor << setw(18 - Skincolor.length() - (18 - Skincolor.length()) / 2) << " "
         << "|" << setw(6) << Thoroughbred_index << setw(3)
         << "|" << setw(8) << Nums << setw(7)
         << "|" << setw(13) << (size_t)Price() << setw(6)
         << "|" << endl;
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    cout << endl;
}

int Pet::getNums()
{
    return this->Nums;
}

void Pet::setNums(int sl)
{
    this->Nums = sl;
}

long long Pet::Price()
{
    if (Skincolor == "trang")
    {
        if (Ageold <= 4)
            return 2000000 + (Ageold - 1) * 2500000;
        else if (Ageold <= 8)
            return 9500000 + Ageold * 687500;
        else if (Ageold <= 12)
            return 15000000 + Ageold * 850000;
        else
            return 18000000;
    }
    else if (Skincolor == "den" || Skincolor == "nau do" || Skincolor == "kem" || Skincolor == "vang")
    {
        if (Ageold <= 4)
            return 1500000 + (Ageold - 1) * 2250000;
        else if (Ageold <= 8)
            return 8250000 + Ageold * 593750;
        else if (Ageold <= 12)
            return 13000000 + Ageold * 585000;
        else
            return 15000000;
    }
    else if (Skincolor == "bo sua")
    {
        if (Ageold <= 4)
            return 3000000 + (Ageold - 1) * 3500000;
        else if (Ageold <= 8)
            return 13500000 + Ageold * 812500;
        else if (Ageold <= 12)
            return 20000000 + Ageold * 900000;
        else
            return 22500000;
    }
    else if (Skincolor == "xam")
    {
        if (Ageold <= 4)
            return 3500000 + (Ageold - 1) * 4000000;
        else if (Ageold <= 8)
            return 15500000 + Ageold * 850000;
        else if (Ageold <= 12)
            return 22300000 + Ageold * 1000000;
        else
            return 25000000;
    }
    else
        return 10000000;
}
