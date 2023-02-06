#include "Receipt.h"
#include <bits/stdc++.h>
#include <fstream>

#define FORE(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

Receipt::Receipt()
{
}

Receipt::~Receipt()
{
}

int Receipt::getMAHD()
{
     return this->MAHD;
}

void Receipt::setMAHD()
{
     this->MAHD = (rand() % 89999) + 10001;
}

void Receipt::HD_print(QLCAT *p, QLDOG *q, Customer *Z, int dog1[], int cat1[], FinanceManage &Y)
{
     long long total = 0;
     FOR(i, 1, 10)
     Receipt::setMAHD();
     cout << setw(65) << "+";
     FOR(i, 1, 70)
     cout << "-";
     cout << "+";
     cout << endl;
     cout << setw(65) << "|"
          << " Ma Hoa Don: HD" << setw(55) << left << this->MAHD << "|" << endl;
     cout << setw(65) << right << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|" << setw(54) << "Da Nang, " << Z->get_ngaymua() << setw(7) << "|" << endl;
     cout << setw(65) << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|" << setw(39) << " HOA DON" << setw(32) << "|" << endl;
     cout << setw(65) << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|"
          << " MA Khach Hang: " << setw(54) << left << Z->get_id() << "|" << endl;
     cout << setw(65) << right << "|"
          << " Ho ten khach hang: " << setw(50) << left << Z->get_ht() << "|" << endl;
     cout << setw(65) << right << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|"
          << " DANH SACH PET DA MUA:" << setw(49) << "|" << endl;
     cout << setw(65) << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|"
          << " MEO" << setw(35) << "SO LUONG" << setw(32) << "THANH TIEN |" << endl;
     int checkpos[5000];
     memset(checkpos, 0, sizeof checkpos);
     FOR(i, 1, Z->ncat)
     {
          if (checkpos[Z->catbuy[i]] == 0)
          {
               checkpos[Z->catbuy[i]] = 1;
               int pp = Z->catbuy[i];
               cout << setw(66) << "| " << setw(28) << left << p->getname_atpos(Z->catbuy[i]);
               cout << setw(10) << right << cat1[pp] << setw(30) << cat1[pp] * p->getPrice_atpos(Z->catbuy[i]) << " |" << endl;
               total += cat1[pp] * p->getPrice_atpos(Z->catbuy[i]);
          }
          else
               continue;
     }
     memset(checkpos, 0, sizeof checkpos);
     cout << setw(65) << right << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|"
          << " CHO" << setw(35) << "SO LUONG" << setw(32) << "THANH TIEN |" << endl;
     FOR(i, 1, Z->ndog)
     {
          if (checkpos[Z->dogbuy[i]] == 0)
          {
               checkpos[Z->dogbuy[i]] = 1;
               int pp = Z->dogbuy[i];
               cout << setw(66) << "| " << setw(28) << left << q->getname_atpos(Z->dogbuy[i]);
               long long zz = dog1[pp] * q->getPrice_atpos(Z->dogbuy[i]);
               cout << setw(10) << right << dog1[pp] << setw(30) << zz << " |" << endl;
               total += dog1[pp] * q->getPrice_atpos(Z->dogbuy[i]);
          }
          else
               continue;
     }
     cout << setw(65) << right << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|"
          << " TONG TIEN THANH TOAN : " << setw(45) << total << " |" << endl;

     Date *ML = new Date(Z->get_ngaymua().Getngay(), Z->get_ngaymua().Getthang(), Z->get_ngaymua().Getnam());
     Y.setatdate(ML->Getthang(), ML->Getnam(), total + Y.getatdate(ML->Getthang(), ML->Getnam()));

     cout << setw(65) << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "|" << setw(50) << "Cam on quy khach da mua hang!" << setw(21) << "|" << endl;
     cout << setw(65) << "|" << setw(52) << "Hen gap lai quy khach vao lan sau" << setw(19) << "|" << endl;
     cout << setw(65) << "|" << setw(71) << "|" << endl;
     cout << setw(65) << "+";
     FOR(i, 1, 70)
     cout << "-";
     cout << "+";
     cout << endl;
}

void Receipt::HD_OUT(QLCAT *p, QLDOG *q, Customer *Z, int dog1[], int cat1[], FinanceManage &Y)
{
     long long total = 0;
     fstream FO;
     FO.open("HD.TXT", ios::app);
     FOR(i, 1, 10)
     Receipt::setMAHD();

     FO << setw(65) << "+";
     FOR(i, 1, 70)
     FO << "-";
     FO << "+";
     FO << endl;
     FO << setw(65) << "|"
        << " Ma Hoa Don: HD" << setw(55) << left << this->MAHD << "|" << endl;
     FO << setw(65) << right << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|" << setw(54) << "Da Nang, " << Z->get_ngaymua() << setw(7) << "|" << endl;
     FO << setw(65) << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|" << setw(39) << " HOA DON" << setw(32) << "|" << endl;
     FO << setw(65) << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|"
        << " MA Khach Hang: " << setw(54) << left << Z->get_id() << "|" << endl;
     FO << setw(65) << right << "|"
        << " Ho ten khach hang: " << setw(50) << left << Z->get_ht() << "|" << endl;
     FO << setw(65) << right << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|"
        << " DANH SACH PET DA MUA:" << setw(49) << "|" << endl;
     FO << setw(65) << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|"
        << " MEO" << setw(35) << "SO LUONG" << setw(32) << "THANH TIEN |" << endl;
     int checkpos[5000];
     memset(checkpos, 0, sizeof checkpos);
     FOR(i, 1, Z->ncat)
     {
          if (checkpos[Z->catbuy[i]] == 0)
          {
               checkpos[Z->catbuy[i]] = 1;
               int pp = Z->catbuy[i];
               FO << setw(66) << "| " << setw(28) << left << p->getname_atpos(Z->catbuy[i]);
               FO << setw(10) << right << cat1[pp] << setw(30) << cat1[pp] * p->getPrice_atpos(Z->catbuy[i]) << " |" << endl;
               total += cat1[pp] * p->getPrice_atpos(Z->catbuy[i]);
          }
          else
               continue;
     }
     memset(checkpos, 0, sizeof checkpos);
     FO << setw(65) << right << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|"
        << " CHO" << setw(35) << "SO LUONG" << setw(32) << "THANH TIEN |" << endl;
     FOR(i, 1, Z->ndog)
     {
          if (checkpos[Z->dogbuy[i]] == 0)
          {
               checkpos[Z->dogbuy[i]] = 1;
               int pp = Z->dogbuy[i];
               FO << setw(66) << "| " << setw(28) << left << q->getname_atpos(Z->dogbuy[i]);
               FO << setw(10) << right << dog1[pp] << setw(30) << dog1[pp] * q->getPrice_atpos(Z->dogbuy[i]) << " |" << endl;
               total += dog1[pp] * q->getPrice_atpos(Z->dogbuy[i]);
          }
          else
               continue;
     }
     FO << setw(65) << right << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|"
        << " TONG TIEN THANH TOAN : " << setw(45) << total << " |" << endl;

     FO << setw(65) << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "|" << setw(50) << "Cam on quy khach da mua hang!" << setw(21) << "|" << endl;
     FO << setw(65) << "|" << setw(52) << "Hen gap lai quy khach vao lan sau" << setw(19) << "|" << endl;
     FO << setw(65) << "|" << setw(71) << "|" << endl;
     FO << setw(65) << "+";
     FOR(i, 1, 70)
     FO << "-";
     FO << "+";
     FO << endl;

     FO << FO.tellp() << endl
        << endl
        << endl
        << endl;
     // streampos pos = FO.tellp();
     //  FO.seekp(3, std::ios_base::end);
}
