#include "QLKH.h"
#include <bits/stdc++.h>

using namespace std;
using std::string;

#define X first
#define Y second
#define FORE(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

QLKH::QLKH(int n)
{
    this->n = n;
    this->D = new Customer[n * n + 10];
}

QLKH::~QLKH()
{
    delete[] this->D;
}

void QLKH::setL(const int &n)
{
    this->n = n;
}

int QLKH::getL()
{
    return this->n;
}

void QLKH::addtail(Customer *Z)
{
    D[++this->n].init(Z->get_id(), Z->get_phone(), Z->get_ht(), Z->get_ngaymua(), Z->get_times());
}

void QLKH::display()
{
    cout << setw(110) << "THONG TIN KHACH HANG" << endl
         << endl;
    FOR(i, 1, this->n)
    D[i].display();
}

void QLKH::inc_time_atpos(int pos)
{
    if (pos < 1 || pos > this->n)
        return;
    D[pos].set_times(D[pos].get_times() + 1);
}

int QLKH::find_phone(string z)
{
    int i = 1;
    while (i <= this->n && D[i].get_phone() != z)
        i++;

    if (i == n + 1)
        return -1;
    else
        return i;
}

string QLKH::getname_atpos(int pos)
{
    if (pos < 1 || pos > this->n)
        return "-1";
    return D[pos].get_ht();
}

int QLKH::get_timeatpos(int pos)
{
    if (pos < 1 || pos > this->n)
        return -1;
    return D[pos].get_times();
}

void QLKH::show_atpos(int pos)
{
    if (pos < 1 || pos > this->n)
        return;
    else
    {
        D[pos].display();
    }
}

int QLKH::get_id_atpos(int pos)
{
    if (pos < 1 || pos > this->n)
        return -1;
    return D[pos].get_id();
}

Date QLKH::get_dateatpos(int pos)
{
    if (pos < 1 || pos > this->n)
        return Date(-1, -1, -1);
    return D[pos].get_ngaymua();
}

void QLKH::find_by_keyword(string z)
{
    FOR(i, 1, this->n)
    if (QLKH::getname_atpos(i).find(z) != -1)
    {
        QLKH::show_atpos(i);
    }
    cout << "\n";
}

void QLKH::update()
{
    string z;
    cout << setw(110) << "NHAP SO DIEN THOAI: ";
    getline(cin >> ws, z);
    if (QLKH::find_phone(z) == -1)
    {
        cout << endl;
        cout << setw(115) << "SO DIEN THOAI KHONG TON TAI!!!" << endl;
    }
    else
    {
        while (true)
        {
            int pos = QLKH::find_phone(z);
            int t;
            system("cls");
            cout << setw(114) << "THONG TIN KHACH HANG UPDATE:" << endl;
            QLKH::show_atpos(pos);
            cout << endl;
            cout << setw(117) << "Ban muon thay doi SDT hay ho ten ?" << endl
                 << endl;
            cout << setw(101) << "1.SDT" << endl;
            cout << setw(104) << "2.Ho ten" << endl;
            cout << setw(103) << "0.Thoat" << endl
                 << endl;
            cout << setw(111) << "Moi ban nhap lua chon: ";
            cin >> t;

            if (t == 1)
            {
                system("cls");
                D[pos].display();
                string NewSDT;
                cout << setw(112) << "Nhap SDT can thay the : ";
                getline(cin >> ws, NewSDT);
                string sure;
                cout << endl;
                cout << setw(142) << "Ban co chac chan voi quyet dinh nay? (Go [ok] neu dong y va [nut khac de tro lai]): ";
                getline(cin >> ws, sure);
                if (sure == "OK" || sure == "ok" || sure == "Ok" || sure == "oK")
                {
                    D[pos].set_phone(NewSDT);
                    cout << endl;
                    cout << setw(103) << "DONE!!" << endl;
                    break;
                }
                else
                    continue;
            }

            else if (t == 2)
            {
                system("cls");
                D[pos].display();
                string NewName;
                cout << setw(115) << "Nhap ho ten KH can thay the : ";
                getline(cin >> ws, NewName);
                string sure;
                cout << endl;
                cout << setw(142) << "Ban co chac chan voi quyet dinh nay? (Go [ok] neu dong y va [nut khac de tro lai]): ";
                getline(cin >> ws, sure);
                if (sure == "OK" || sure == "ok" || sure == "Ok" || sure == "oK")
                {
                    D[pos].set_ht(NewName);
                    cout << endl;
                    cout << setw(103) << "DONE!!" << endl;
                    break;
                }
                else
                    continue;
            }
            else if (t == 0)
            {
                cout << endl;
                break;
            }
            else
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
        }
    }
}

void QLKH::delete1(string Z)
{
    int pos = QLKH::find_phone(Z);
    if (pos == -1)
    {
        cout << endl;
        cout << setw(115) << "SO DIEN THOAI KHONG TON TAI!!!" << endl;
    }
    else
    {
        system("cls");
        cout << setw(114) << "THONG TIN KHACH HANG CO SDT " << Z << " LA:" << endl
             << endl;
        QLKH::show_atpos(pos);
        string sure;
        cout << setw(142) << "Ban co chac chan voi quyet dinh nay? (Go [ok] neu dong y va [nut khac de tro lai]): ";
        getline(cin >> ws, sure);
        if (sure == "OK" || sure == "ok" || sure == "Ok" || sure == "oK")
        {
            FOR(i, pos + 1, n)
            D[i - 1] = D[i];
            n = n - 1;
            cout << endl;
            cout << setw(109) << "Xoa thanh cong!!!!" << endl
                 << endl;
        }
        else
            return;
    }
}

void QLKH::file_readKH()
{
    ifstream inpKH;
    inpKH.open("CUSTOMER.txt", ios::in);
    if (inpKH.fail())
    {
        cout << setw(118) << "CHECK THE PATH FILE AND TRY AGAIN!!!" << endl;
        system("pause");
        return;
    }

    int newsize;
    inpKH >> newsize;
    this->n = newsize;
    delete[] this->D;
    this->D = new Customer[n * n + 15];
    int a, e, day, month, year;
    string b, c;
    Date d;
    int i = 1;
    while (i != this->n + 1 && !inpKH.eof())
    {
        inpKH >> a;
        inpKH.ignore(1);
        getline(inpKH >> ws, b, ',');
        getline(inpKH >> ws, c, ',');
        inpKH >> day;
        d.Setngay(day);
        inpKH.ignore(1);
        inpKH >> month;
        d.Setthang(month);
        inpKH.ignore(1);
        inpKH >> year;
        d.Setnam(year);
        inpKH.ignore(1);
        inpKH >> e;
        D[i].init(a, b, c, d, e);
        i++;
    }
    cout << endl;
}

void QLKH::writeF()
{
    ofstream o;
    o.open("CUSTOMER.txt", ios::out);
    o << this->n << endl;
    FOR(i, 1, this->n)
    {
        o << D[i].get_id() << ", "
          << D[i].get_phone() << ", "
          << D[i].get_ht() << ", "
          << D[i].get_ngaymua() << ", "
          << D[i].get_times();
        o << "\n";
    }
    o.close();
}

void QLKH::menu_for_QLKH()
{

    while (true)
    {
        int opt;
        system("cls");
        cout << setw(133) << "+-----------------------------------------------------------------+" << endl;
        cout << setw(133) << "|                 CHUONG TRINH QUAN LY KHACH HANG                 |" << endl;
        cout << setw(133) << "|1. Xuat thong tin khach hang                                     |" << endl;
        cout << setw(133) << "|2. Cap nhat thong tin khach hang                                 |" << endl;
        cout << setw(133) << "|3. Tim kiem khach hang theo SDT                                  |" << endl;
        cout << setw(133) << "|4. Xoa thong tin khach hang                                      |" << endl;
        cout << setw(133) << "|5. Them thong tin khach hang tai cuoi DS                         |" << endl;
        cout << setw(133) << "|6. Tim kiem khach hang theo ten tu khoa                          |" << endl;
        cout << setw(133) << "|0. Quay tro ve.                                                  |" << endl;
        cout << setw(133) << "|                               END                               |" << endl;
        cout << setw(133) << "+-----------------------------------------------------------------+" << endl
             << endl
             << endl;

        cout << setw(111) << "Moi ban nhap lua chon: ";
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

        if (opt == 1)
        {
            system("cls");
            QLKH::display();
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 2)
        {
            system("cls");
            QLKH::display();
            QLKH::update();
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 3)
        {
            system("cls");
            string z;
            cout << setw(109) << "Nhap SDT can tim: ";
            getline(cin >> ws, z);

            if (QLKH::find_phone(z) != -1)
                QLKH::show_atpos(QLKH::find_phone(z));

            else
                cout << setw(113) << "NOT FOUND WITH THAT TEL.NO" << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 4)
        {
            system("cls");
            QLKH::display();
            string sdt;
            cout << setw(110) << "Nhap so dien thoai: ";
            getline(cin >> ws, sdt);
            QLKH::delete1(sdt);
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 5)
        {
            cout << endl;
            string a, b;
            Date c;
            int d;
            cout << setw(113) << "THONG TIN KHACH HANG THEM:" << endl
                 << endl;
            cout << setw(101) << "MOI NHAP SDT: ";
            getline(cin >> ws, a);
            cout << setw(104) << "MOI NHAP ho ten: ";
            getline(cin >> ws, b);
            cin >> c;
            cout << endl
                 << endl;
            cout << setw(104) << "Nhap so lan mua: ";
            cin >> d;
            Customer *Z = new Customer(rand() % 89999 + 10001, a, b, c, d);
            QLKH::addtail(Z);
            delete Z;
            cout << endl;
            cout << setw(103) << "DONE!!" << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 6)
        {
            system("cls");
            string keyword;
            cout << setw(113) << "Nhap tu khoa ten can tim: ";
            getline(cin >> ws, keyword);
            cout << endl;
            QLKH::find_by_keyword(keyword);
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 0)
            break;

        else
        {
            cout << endl;
            cout << setw(122) << "Lua chon khong hop le. Moi nhap lai lua chon" << endl
                 << endl;
            cout << setw(83) << " ";
            system("pause");
        }
    }
}