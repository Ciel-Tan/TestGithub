#include "ArrayofFinance.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <limits>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)

FinanceManage::~FinanceManage()
{
    delete[] this->E;
}

FinanceManage::FinanceManage()
{
    int k = 1950;
    FOR(i, 1, 12600)
    {
        E[i].setbill(0);
        E[i].setmonth(i % 12 + 1);
        E[i].setyear(k);
        if ((i + 2) % 12 == 1)
            k++;
    }
}

long long FinanceManage::getatdate(int month, int year)
{
    if (month < 0 || month > 12 || year < 1950 || year >= 3000)
        return -1;
    else
    {
        return this->E[(year - 1 - 1950 + 1) * 12 + month - 1].getbill();
    }
}

void FinanceManage::display()
{
    cout << setw(120) << "+-------------------+------------------+" << endl;
    cout << setw(120) << "|  DOANH THU THANG  |     TIEN MAT     |" << endl;
    cout << setw(120) << "+-------------------+------------------+" << endl;
    FOR(i, 1, 12600)
    if (this->E[i].getbill() > 0)
    {

        if (this->E[i].getmonth() >= 10)
        {
            cout << setw(81) << "|" << setw(8) << this->E[i].getmonth() << "/" << this->E[i].getyear() << setw(7)
                 << "|" << setw(14) << this->E[i].getbill() << setw(5)
                 << "|" << endl;
            cout << setw(120) << "+-------------------+------------------+" << endl;
        }
        else
        {
            cout << setw(81) << "|" << setw(7) << "0" << this->E[i].getmonth() << "/" << this->E[i].getyear() << setw(7)
                 << "|" << setw(14) << this->E[i].getbill() << setw(5)
                 << "|" << endl;
            cout << setw(120) << "+-------------------+------------------+" << endl;
        }
    }
}

// void FinanceManage::displayA()
// {
//     cout << setw(120) << "+-------------------+------------------+" << endl;
//     cout << setw(120) << "|  DOANH THU THANG  |     TIEN MAT     |" << endl;
//     cout << setw(120) << "+-------------------+------------------+" << endl;
//     FOR(i, 1, 12600)
//     {
//         if (this->E[i].getmonth() >= 10)
//         {
//             cout << setw(81) << "|" << setw(8) << this->E[i].getmonth() << "/" << this->E[i].getyear() << setw(7)
//                  << "|" << setw(14) << this->E[i].getbill() << setw(5)
//                  << "|" << endl;
//             cout << setw(120) << "+-------------------+------------------+" << endl;
//         }
//         else
//         {
//             cout << setw(81) << "|" << setw(7) << "0" << this->E[i].getmonth() << "/" << this->E[i].getyear() << setw(7)
//                  << "|" << setw(14) << this->E[i].getbill() << setw(5)
//                  << "|" << endl;
//             cout << setw(120) << "+-------------------+------------------+" << endl;
//         }
//     }
// }

void FinanceManage::setatdate(int thang, int nam, long long hd)
{
    if (thang < 0 || thang > 12 || nam < 1950 || nam >= 3000)
        return;
    else
        this->E[(nam - 1 - 1950 + 1) * 12 + thang - 1].setbill(hd);
}

void FinanceManage::displayat(int thang, int nam)
{
    if (thang < 0 || thang > 12 || nam < 1950 || nam >= 3000)
        return;
    else
    {
        int L = 1;
        FOR(i, 1950, 2999)
        {
            FOR(j, 1, 12)
            {
                if (j == thang && i == nam)
                {
                    cout << setw(120) << "+-------------------+------------------+" << endl;
                    cout << setw(120) << "|  DOANH THU THANG  |     TIEN MAT     |" << endl;
                    cout << setw(120) << "+-------------------+------------------+" << endl;
                    cout << setw(81) << "|" << setw(8) << this->E[L - 1].getmonth() << "/" << this->E[L - 1].getyear() << setw(7)
                         << "|" << setw(14) << this->E[L - 1].getbill() << setw(5)
                         << "|" << endl;
                    cout << setw(120) << "+-------------------+------------------+" << endl;
                }
                // cout << endl
                //      << setw(100)<< this->E[L - 1].getmonth() << "/" << this->E[L - 1].getyear() << "\t\t" << this->E[L - 1].getbill() << endl;
                L++;
            }
        }
    }
}

long long FinanceManage::FinanceAt(int thang, int nam)
{
    int L = 1;
    long long res = 0;
    FOR(i, 1950, 2999)
    FOR(j, 1, 12)
    {
        if (j == thang && i == nam)
        {
            res = this->E[L - 1].getbill();
            break;
        }
        L++;
    }
    return res;
}

void FinanceManage::writeF()
{
    ofstream FO;
    FO.open("FINANCE.TXT", ios::out);
    FOR(i, 1, 12600)
    if (this->E[i].getbill() > 0)
    {
        FO << this->E[i].getmonth() << "/" << this->E[i].getyear() << " " << this->E[i].getbill() << endl;
    }
    FO.close();
}

void FinanceManage::FinitF()
{
    ifstream FI;
    FI.open("FINANCE.TXT", ios::in);
    if (FI.fail())
    {
        cout << setw(118) << "CHECK THE PATH FILE AND TRY AGAIN!!!" << endl;
        system("pause");
        return;
    }
    while (!FI.eof())
    {
        int a, b;
        long long c;
        FI >> a;
        FI.ignore(1);
        FI >> b;
        FI.ignore(1);
        FI >> c;
        FI.ignore(1);
        if (a < 0 || a > 12 || b >= 3000 || b < 1950)
            continue;
        else
        {
            this->E[(b - 1 - 1950 + 1) * 12 + a - 1].setbill(c);
        }
    }
    FI.close();
}

void FinanceManage::memu()
{
    while (true)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 13);

        int opt;
        system("cls");
        Sleep(35);
        cout << setw(134) << "+-----------------------------------------------------------------+" << endl;
        Sleep(35);
        cout << setw(134) << "|                MENU QUAN LY TAI CHINH - DOANH THU               |" << endl;
        Sleep(35);
        cout << setw(134) << "|1.In ra thong tin doanh thu tung thang                           |" << endl;
        Sleep(35);
        cout << setw(134) << "|2.In ra doanh thu cua thang cu the                               |" << endl;
        Sleep(35);
        cout << setw(134) << "|3.So sanh                                                        |" << endl;
        Sleep(35);
        cout << setw(134) << "|4.Quan ly doanh thu cua thang                                    |" << endl;
        Sleep(35);
        cout << setw(134) << "|0.Thoat chuong trinh                                             |" << endl;
        Sleep(35);
        cout << setw(134) << "|                               END                               |" << endl;
        Sleep(35);
        cout << setw(134) << "+-----------------------------------------------------------------+" << endl
             << endl;

        Sleep(35);

        cout << setw(112) << "Moi ban nhap lua chon: ";
        cin >> opt;
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl
                 << endl;
            cout << setw(122) << "Lua chon khong hop le. Moi nhap lai lua chon" << endl
                 << endl;
            cout << setw(83) << " ";
            system("pause");
            continue;
        }
        if (opt == 0)
        {
            break;
        }

        else if (opt == 1)
        {
            FinanceManage::display();
            cout << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 2)
        {
            int a, b;
            cout << endl;
            cout << setw(108) << "Moi nhap thang: ";
            cin >> a;
            cout << endl;
            cout << setw(106) << "Moi nhap nam: ";
            cin >> b;
            if (a < 0 || a > 12 || b >= 3000 || b < 1950)
            {
                cout << endl;
                cout << setw(120) << "INVAILD NUMBER! PLEASE TRY AGAIN LATER!!" << endl;
                cout << endl;
                cout << setw(83) << " ";
                system("pause");
            }
            else
            {
                FinanceManage::displayat(a, b);
                cout << endl;
                cout << setw(83) << " ";
                system("pause");
            }
        }

        else if (opt == 3)
        {
            int a1, b1;
            long long F1 = 0;

            int a2, b2;
            long long F2 = 0;

            cout << endl;
            cout << setw(114) << "Moi nhap thang thu nhat: ";
            cin >> a1;
            cout << endl;
            cout << setw(112) << "Moi nhap nam thu nhat: ";
            cin >> b1;
            if (a1 < 0 || a1 > 12 || b1 >= 3000 || b1 < 1950)
            {
                cout << endl;
                cout << setw(120) << "INVAILD NUMBER! PLEASE TRY AGAIN LATER!!" << endl;
                cout << endl;
                cout << setw(83) << " ";
                system("pause");
            }
            else if (FinanceManage::FinanceAt(a1, b1) > 0)
                F1 = FinanceManage::FinanceAt(a1, b1);
            cout << endl;
            cout << setw(100) << "Doanh thu thang " << a1 << "/" << b1 << " la: " << F1;
            cout << endl
                 << endl;
            cout << setw(122) << "//-----------------/-----------------//" << endl;
            cout << endl;
            cout << setw(113) << "Moi nhap thang thu hai: ";
            cin >> a2;
            cout << endl;
            cout << setw(111) << "Moi nhap nam thu hai: ";
            cin >> b2;
            if (a2 < 0 || a2 > 12 || b2 >= 3000 || b2 < 1950)
            {
                cout << endl;
                cout << setw(120) << "INVAILD NUMBER! PLEASE TRY AGAIN LATER!!" << endl;
                cout << endl;
                cout << setw(83) << " ";
                system("pause");
            }
            else if (FinanceManage::FinanceAt(a2, b2) > 0)
                F2 = FinanceManage::FinanceAt(a2, b2);
            cout << endl;
            cout << setw(100) << "Doanh thu thang " << a2 << "/" << b2 << " la: " << F2;
            if (F1 == 0 || F2 == 0)
            {
                cout << endl;
                cout << setw(118) << "THERE ARE NO FINNANCE AT THESE DATE!" << endl;
                cout << endl;
                cout << setw(83) << " ";
                system("pause");
            }
            else
            {
                cout << endl
                     << endl;
                cout << setw(122) << "//-----------------/-----------------//" << endl;
                cout << endl;
                if (F1 > F2)
                {
                    cout << setw(85) << "+ Doanh thu thang " << a1 << "/" << b1 << " nhieu hon doanh thu thang " << a2 << "/" << b2 << " la: " << F1 - F2 << endl;
                    cout << setw(85) << "+ Doanh thu thang " << a1 << "/" << b1 << " gap " << (double)F1 / F2 << " lan so voi doanh thu " << a2 << "/" << b2 << endl;
                }
                if (F1 < F2)
                {
                    cout << setw(85) << "+ Doanh thu thang " << a2 << "/" << b2 << " nhieu hon doanh thu thang " << a1 << "/" << b1 << " la: " << F2 - F1 << endl;
                    cout << setw(85) << "+ Doanh thu thang " << a2 << "/" << b2 << " gap " << (double)F2 / F1 << " lan so voi doanh thu " << a1 << "/" << b1 << endl;
                }
                if (F1 == F2)
                {
                    cout << setw(117) << "+ Doanh thu 2 thang la ngang nhau:" << endl;
                }
                cout << endl;
                cout << setw(83) << " ";
                system("pause");
            }
        }

        else if (opt == 4)
        {
            int a, b;
            long long c;
            cout << endl;
            cout << setw(108) << "Moi nhap thang: ";
            cin >> a;
            cout << endl;
            cout << setw(106) << "Moi nhap nam: ";
            cin >> b;
            if (a < 0 || a > 12 || b >= 3000 || b < 1950)
            {
                cout << endl;
                cout << setw(120) << "INVAILD NUMBER! PLEASE TRY AGAIN LATER!!" << endl;
                cout << endl;
                cout << setw(83) << " ";
                system("pause");
            }
            else
            {
                cout << endl;
                cout << setw(115) << "Moi nhap doanh so (co the am): ";
                cin >> c;
                string sure;
                cout << setw(142) << "Ban co chac chan voi quyet dinh nay? (Go [ok] neu dong y va [nut khac de tro lai]): ";
                getline(cin >> ws, sure);
                if (sure == "OK" || sure == "ok" || sure == "Ok" || sure == "oK")
                {
                    FinanceManage::setatdate(a, b, c);
                    cout << endl;
                    cout << setw(103) << "DONE!!" << endl
                         << endl;
                    cout << setw(84) << " ";
                    system("pause");
                }
                else
                    return;
            }
        }
    }
}