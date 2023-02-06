#include <bits/stdc++.h>
#include "QLNV.h"
#include <fstream>

using namespace std;

#define X first
#define Y second
#define FORE(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

QLNV::QLNV(int n)
{
    this->n = n;
    C = new NhanVien[n * n + 15];
}

QLNV::~QLNV()
{
    delete[] C;
}

int QLNV::getL()
{
    return this->n;
}

void QLNV::setL(const int &n)
{
    this->n = n;
}

void QLNV::renew_ofsize(const int &n)
{
    this->n = n;
    this->C = new NhanVien[n * n + 15];
}

void QLNV::init()
{
    FOR(i, 1, this->n)
    {
        system("cls");
        cout << endl;
        cout << setw(114) << "NHAP THONG TIN NHAN VIEN THU " << i << endl
             << endl;

        string s;
        cout << setw(94) << "Nhap id: ";
        getline(cin >> ws, s);
        while (1)
        {
            if (s[0] != 'N' || s[1] != 'V')
            {
                cout << setw(129) << "Ki tu dau cua ID phai la NV!, moi nhap lai: ";
                getline(cin >> ws, s);
            }
            else
                break;
        }

        while (1)
        {
            int ck = 0;
            FOR(j, 1, i - 1)
            if (s == C[j].GetID())
            {
                cout << setw(122) << "ID DA BI TRUNG, MOI BAN NHAP LAI !:  ";
                ck = 1;
                getline(cin >> ws, s);
                while (1)
                {
                    if (s[0] != 'N' || s[1] != 'V')
                    {
                        cout << setw(129) << "Ki tu dau cua ID phai la D!, moi nhap lai: ";
                        getline(cin >> ws, s);
                    }
                    else
                        break;
                }
                break;
            }
            if (ck == 0)
                break;
        }

        C[i].SetID(s);

        C[i].Input();
        cout << endl
             << endl;
    }
}

void QLNV::display()
{
    cout << setw(158) << "+----------+----------------------------+--------+-------------+---------------+----------------+-----------------+\n";
    cout << setw(158) << "|    ID    |          HO VA TEN         |  TUOI  |  GIOI TINH  |  HE SO LUONG  |  LUONG CO BAN  |      LUONG      |\n";
    cout << setw(158) << "+----------+----------------------------+--------+-------------+---------------+----------------+-----------------+\n";
    FOR(i, 1, n)
    {
        cout << setw(43) << "|" << setw((10 - C[i].GetID().length()) / 2) << " " << C[i].GetID() << setw(11 - C[i].GetID().length() - (10 - C[i].GetID().length()) / 2)
             << "|" << setw((28 - C[i].GetName().length()) / 2) << " " << C[i].GetName() << setw(29 - C[i].GetName().length() - (28 - C[i].GetName().length()) / 2)
             << "|" << setw(5) << C[i].GetAge() << setw(4)
             << "|" << setw((13 - C[i].GetGender().length()) / 2) << " " << C[i].GetGender() << setw(14 - C[i].GetGender().length() - (13 - C[i].GetGender().length()) / 2)
             << "|" << setw(9) << C[i].GetHeSoLuong() << setw(7)
             << "|" << setw(12) << (size_t)C[i].GetLuongCoBan() << setw(5)
             << "|" << setw(13) << (size_t)C[i].Salary() << setw(5)
             << "|" << endl;
        cout << setw(158) << "+----------+----------------------------+--------+-------------+---------------+----------------+-----------------+\n";
    }
    cout << endl;
}

void QLNV::addMiddle(const NhanVien &Z, int pos)
{
    if (pos == n || pos == n + 1)
        C[++n] = Z;
    else
    {
        this->n++;
        FOD(i, this->n, pos + 1)
        C[i] = C[i - 1];
        C[pos] = Z;
    }
}

void QLNV::findofID(string id)
{
    int i = 1;
    while (i <= n && C[i].GetID() != id)
        i++;

    if (i == n + 1)
    {
        system("cls");
        QLNV::display();
        cout << setw(98) << "KHONG TON TAI ID " << id << " TRONG DANH SACH!" << endl;
    }
    else
    {
        system("cls");
        QLNV::display();
        cout << setw(109) << "THONG TIN NHAN VIEN CO ID " << id << " LA:" << endl;
        C[i].Output();
    }
}

int QLNV::findofID2(string x)
{
    int i = 1;
    while (i <= n && C[i].GetID() != x)
    {
        i++;
    }
    if (i == n + 1)
        return -1;
    else
        return i;
}

void QLNV::delete_atpos(string id)
{
    int pos = 1;
    while (pos <= n && C[pos].GetID() != id)
        pos++;

    if (pos > n)
    {
        cout << endl;
        cout << setw(98) << "Khong ton tai id " << id << " trong danh sach!" << endl;
    }
    else
    {
        system("cls");
        cout << setw(109) << "THONG TIN NHAN VIEN CO ID " << id << " LA:" << endl
             << endl;
        C[pos].Output();
        cout << endl;
        string sure;
        cout << setw(142) << "Ban co chac chan voi quyet dinh nay? (Go [ok] neu dong y va [nut khac de tro lai]): ";
        getline(cin >> ws, sure);

        if (sure == "OK" || sure == "ok" || sure == "Ok" || sure == "oK")
        {
            FOR(i, pos + 1, n)
            C[i - 1] = C[i];
            n = n - 1;
            cout << endl;
            cout << setw(108) << "Xoa thanh cong!!" << endl
                 << endl;
        }
        else
            return;
    }
}

void QLNV::update()
{
    string id;
    cout << setw(115) << "NHAP ID NHAN VIEN CAN UPDATE: ";
    getline(cin >> ws, id);
    if (QLNV::findofID2(id) == -1)
    {
        system("cls");
        QLNV::display();
        cout << setw(98) << "KHONG TON TAI ID " << id << " TRONG DANH SACH!" << endl;
    }
    else
    {
        while (true)
        {
            int c = -1;
            int pos = QLNV::findofID2(id);
            system("cls");
            cout << setw(115) << "THONG TIN NHAN VIEN CAN UPDATE:" << endl
                 << endl;
            C[pos].Output();
            cout << setw(120) << "LUA CHON THONG TIN NHAN VIEN CAN UPDATE:" << endl
                 << endl;
            cout << setw(92) << "1. Ho va ten" << setw(28) << "3. Gioi tinh" << endl;
            cout << setw(104) << "0. Thoat" << endl;
            cout << setw(87) << "2. Tuoi" << setw(33) << "4. He so luong" << endl
                 << endl;

            cout << setw(117) << "Nhap lua chon cap nhat thong tin: ";
            cin >> c;
            if (c == 1)
            {
                system("cls");
                C[pos].Output();
                string NewName;
                cout << setw(100) << "Nhap ho ten muon chinh sua: ";
                getline(cin >> ws, NewName);
                C[pos].SetName(NewName);
                cout << endl;
                cout << setw(114) << "Chinh sua ten thanh cong" << endl;
                break;
            }
            else if (c == 2)
            {
                system("cls");
                C[pos].Output();
                int NewAge;
                cout << setw(113) << "Nhap tuoi muon chinh sua: ";
                cin >> NewAge;
                C[pos].SetAge(NewAge);
                cout << endl;
                cout << setw(114) << "Chinh sua tuoi thanh cong" << endl;
                break;
            }
            else if (c == 3)
            {
                system("cls");
                C[pos].Output();
                string NewGender;
                cout << setw(113) << "Nhap gioi tinh (Nam / Nu): ";
                getline(cin >> ws, NewGender);
                if (NewGender == "NAM" || NewGender == "Nam" || NewGender == "nAm" || NewGender == "naM" || NewGender == "NAm" || NewGender == "nAM" || NewGender == "nam")
                    C[pos].SetGender("Nam");
                else if (NewGender == "nu" || NewGender == "NU" || NewGender == "nU" || NewGender == "Nu")
                    C[pos].SetGender("Nu");
                else
                {
                    NewGender = "Unknown";
                    C[pos].SetGender(NewGender);
                }
                cout << endl;
                cout << setw(115) << "Chinh sua gioi tinh thanh cong" << endl;
                break;
            }
            else if (c == 4)
            {
                system("cls");
                C[pos].Output();
                float NewHSL;
                cout << setw(109) << "Nhap he so luong: ";
                cin >> NewHSL;
                C[pos].SetHeSoLuong(NewHSL);
                cout << endl;
                cout << setw(116) << "Chinh sua he so luong thanh cong" << endl;
                break;
            }
            else if (c == 0)
            {
                cout << endl;
                break;
            }
            else
            {
                system("cls");
                C[pos].Output();
                cout << setw(116) << "Lua chon khong hop le. Moi nhap lai" << endl;
                cout << setw(83) << " ";
                system("pause");
                continue;
            }
        }
    }
}

bool ascending(float a, float b)
{
    return a > b;
}

bool decending(float a, float b)
{
    return a < b;
}

void QLNV::sort_bySalindex(bool cmp(float, float))
{
    FOR(i, 1, this->n - 1)
    FOR(j, i + 1, this->n)
    if (cmp(C[i].Salary(), C[j].Salary()))
    {

        NhanVien temp = C[i];

        C[i] = C[j];

        C[j] = temp;
    }
}

void QLNV::file_initEMP()
{
    ifstream inpEMP;
    inpEMP.open("NHANVIEN.txt", ios::in);
    if (inpEMP.fail())
    {
        cout << setw(118) << "CHECK THE PATH FILE AND TRY AGAIN!!!" << endl;
        system("pause");
        return;
    }
    int newsize;
    inpEMP >> newsize;
    QLNV::renew_ofsize(newsize);
    string a, b, d;
    int c;
    float e, f;
    int i = 1;
    while (i != this->n + 1 && !inpEMP.eof())
    {
        getline(inpEMP >> ws, a, ',');
        getline(inpEMP >> ws, b, ',');
        inpEMP >> c;
        inpEMP.ignore(1);
        getline(inpEMP >> ws, d, ',');
        inpEMP >> e;
        inpEMP.ignore(1);
        inpEMP >> f;
        inpEMP.ignore(1);
        C[i].init(a, b, c, d, e, f);
        i++;
    }
    inpEMP.close();
}

void QLNV::writef()
{
    ofstream fileout;
    fileout.open("NHANVIEN.txt", ios::out);
    fileout.seekp(n, ios::end);
    fileout << "\n\n";
    FOR(i, 1, n)
    {
        fileout << C[i].GetID() << ", " << C[i].GetName() << ", " << C[i].GetAge() << ", " << C[i].GetGender() << ", " << C[i].GetHeSoLuong() << ", " << C[i].GetLuongCoBan() << endl;
        fileout << "\n";
    }
    fileout.close();
}

void QLNV::menu_emp()
{
    while (1)
    {
        int opt;
        system("cls");
        cout << setw(145) << "===========================================================================================" << endl;
        cout << setw(145) << "||                       CHUONG TRINH QUAN LY NHAN VIEN (EMPLOYEE)                       ||" << endl;
        cout << setw(145) << "||                                                                                       ||" << endl;
        cout << setw(145) << "||1.Nhap thong tin NV                           6.Xoa thong tin NV theo id               ||" << endl;
        cout << setw(145) << "||2.Xuat thong tin NV                           7.Doc DL TU FILE CO SAN                  ||" << endl;
        cout << setw(145) << "||3.Them thong tin NV vao cuoi danh sach        8.SAP XEP LUONG NV TU THAP DEN CAO       ||" << endl;
        cout << setw(145) << "||4.Cap nhat thong tin NV                       9.SAP XEP LUONG NV TU CAO DEN THAP       ||" << endl;
        cout << setw(145) << "||5.Tim thong tin NV theo id                    0. QUAY TRO LAI                          ||" << endl;
        cout << setw(145) << "||                                                                                       ||" << endl;
        cout << setw(145) << "||                                          END                                          ||" << endl;
        cout << setw(145) << "===========================================================================================" << endl
             << endl;

        cout << setw(109) << "MOI NHAP LUA CHON: ";
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
            system("cls");
            int sz;
            cout << setw(119) << "Nhap so luong nhan vien can khoi tao: ";
            cin >> sz;
            this->n = sz;
            QLNV::renew_ofsize(this->n);
            QLNV::init();
            cout << setw(103) << "DONE!!" << endl;
            cout << setw(83) << " ";
            system("pause");
        }
        else if (opt == 2)
        {
            QLNV::display();
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 3)
        {
            system("cls");
            QLNV::display();
            cout << endl
                 << endl;
            string a, b, d;
            int c;

            float e, f;
            cout << setw(114) << "THONG TIN EMPLOYEE CAN THEM:" << endl
                 << endl;
            cout << setw(95) << "Nhap id: ";
            getline(cin >> ws, a);
            if (this->n >= 1)
            {
                while (1)
                {
                    int ck = 0;
                    FOR(i, 1, this->n)
                    if (a == C[i].GetID())
                    {
                        cout << setw(122) << "ID DA BI TRUNG, MOI BAN NHAP LAI !:  ";
                        ck = 1;
                        getline(cin >> ws, a);
                        break;
                    }
                    if (ck == 0)
                        break;
                }
            }

            cout << setw(104) << "Ho ten nhan vien: ";
            getline(cin >> ws, b);

            cout << setw(92) << "Tuoi: ";
            cin >> c;

            cout << setw(97) << "Gioi tinh: ";
            getline(cin >> ws, d);

            cout << setw(99) << "He so luong: ";
            cin >> e;

            cout << setw(100) << "Luong co ban: ";
            cin >> f;

            NhanVien *Z = new NhanVien();
            Z->init(a, b, c, d, e, f);
            QLNV::addMiddle(*Z, n);
            delete Z;
            cout << endl;
            cout << setw(103) << "DONE!!" << endl
                 << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 4)
        {
            system("cls");
            QLNV::display();
            QLNV::update();

            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 5)
        {
            system("cls");
            QLNV::display();
            string id;

            cout << setw(114) << "Nhap id em[p]loyee can tim: ";
            getline(cin >> ws, id);

            QLNV::findofID(id);
            cout << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 6)
        {
            system("cls");
            QLNV::display();
            string id;
            cout << setw(114) << "Nhap id em[p]loyee can xoa: ";
            getline(cin >> ws, id);
            QLNV::delete_atpos(id);
            cout << setw(86) << " ";
            system("pause");
        }

        else if (opt == 7)
        {
            QLNV::file_initEMP();
            cout << endl;
            cout << setw(103) << "DONE!!" << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 8)
        {
            system("cls");
            QLNV::sort_bySalindex(ascending);
            cout << setw(118) << "BANG LUONG NHAN VIEN TU THAP DEN CAO:" << endl
                 << endl;
            QLNV::display();
            cout << setw(103) << "DONE!!" << endl;
            cout << setw(83) << " ";
            system("pause");
        }
        else if (opt == 9)
        {
            system("cls");
            QLNV::sort_bySalindex(decending);
            cout << setw(118) << "BANG LUONG NHAN VIEN TU CAO DEN THAP:" << endl
                 << endl;
            QLNV::display();
            cout << setw(103) << "DONE!!" << endl;
            cout << setw(83) << " ";
            system("pause");
        }
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