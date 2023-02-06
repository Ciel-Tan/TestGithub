#include <bits/stdc++.h>
#include "shopmanage.h"
using namespace std;

#define _CRT_SECURE_NO_WARNINGS_
#define bitcountO1(mask) __builtin_popcount(mask)
#define pb(x) push_back(x)
#define mp make_pair
#define X first
#define Y second
#define FORE(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

QLCAT::QLCAT(int n)
{
    A = new Cat[n * n];
}

QLCAT::~QLCAT()
{
    delete[] A;
}

int QLCAT::Getn()
{
    return this->n;
}

void QLCAT::Setn(int N)
{
    this->n = N;
}

int QLCAT::getsl_atpos(int pos)
{
    return A[pos].getNums();
}

void QLCAT::setsl_atpos(int pos, int sl)
{
    A[pos].setNums(sl);
}

void QLCAT::init()
{
    cout << setw(114) << "Nhap so luong meo muon them: ";
    int k;
    cin >> k;
    Cat *Z = new Cat;
    FOR(i, 1, k)
    {
        cout << endl;
        system("cls");
        cout << setw(114) << "NHAP THONG TIN LOAI MEO THU " << i << endl
             << endl;
        string s = "-";
        cout << setw(99) << "Nhap id meo: ";
        getline(cin >> ws, s);
        while (1)
        {
            if (s[0] != 'C')
            {
                cout << setw(129) << "Ki tu dau cua ID phai la C!, moi nhap lai: ";
                getline(cin >> ws, s);
            }
            else
                break;
        }
        while (1)
        {
            int ck = 0;
            FOR(j, 1, this->n)
            if (s == A[j].getKey())
            {
                cout << setw(123) << "ID DA BI TRUNG, MOI BAN NHAP LAI !:  ";
                ck = 1;
                getline(cin >> ws, s);
                while (1)
                {
                    if (s[0] != 'C')
                    {
                        cout << setw(129) << "Ki tu dau cua ID phai la C!, moi nhap lai: ";
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
        Z->setKey(s);
        Z->Input();
        QLCAT::addcat(this->n, Z);
    }
    cout << endl;
}

void QLCAT::showforcat()
{
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    cout << setw(168) << "|    ID    |        TEN KHOA HOC        |  TUOI  | CHIEU CAO | CAN NANG |     MAU LONG     |  CSTH  |   SO LUONG   |    THANH TIEN    |\n";
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    FOR(i, 1, n)
    {
        cout << setw(33) << "|" << setw((10 - A[i].getKey().length()) / 2) << " " << A[i].getKey() << setw(10 - A[i].getKey().length() - (10 - A[i].getKey().length()) / 2) << " "
             << "|" << setw((28 - A[i].GetBinomial_nomenclature().length()) / 2) << " " << A[i].GetBinomial_nomenclature() << setw(28 - A[i].GetBinomial_nomenclature().length() - (28 - A[i].GetBinomial_nomenclature().length()) / 2) << " "
             << "|" << setw(5) << A[i].GetAgeold() << setw(4)
             << "|" << setw(7) << A[i].GetHeight() << setw(5)
             << "|" << setw(7) << A[i].GetWeight() << setw(4)
             << "|" << setw((18 - A[i].GetSkincolor().length()) / 2) << " " << A[i].GetSkincolor() << setw(18 - A[i].GetSkincolor().length() - (18 - A[i].GetSkincolor().length()) / 2) << " "
             << "|" << setw(6) << A[i].GetThoroughbred_index() << setw(3)
             << "|" << setw(8) << A[i].getNums() << setw(7)
             << "|" << setw(13) << (size_t)A[i].Price() << setw(6)
             << "|" << endl;
        cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    }
    cout << endl;
}

void QLCAT::addcat(int pos, Cat *Z)
{
    if (pos == n || pos == n + 1)
        A[++n] = Z;
    else
    {
        FOD(i, n + 1, pos + 1)
        A[i] = A[i - 1];
        A[pos] = Z;
        n++;
    }
}

void QLCAT::findcat(string id)
{
    int i = 1;
    while (i <= n && A[i].getKey() != id)
        i++;

    if (i == n + 1)
    {
        system("cls");
        QLCAT::showforcat();
        cout << setw(98) << "Khong ton tai id " << id << " trong danh sach!" << endl;
    }
    else
    {
        system("cls");
        cout << setw(106) << "Thong tin meo co id " << id << " la:" << endl;
        A[i].Output();
    }
}

void QLCAT::delete_atpos(string id)
{
    int pos = 1;
    while (pos <= n && A[pos].getKey() != id)
        pos++;

    if (pos > n)
    {
        cout << endl;
        cout << setw(98) << "Khong ton tai id " << id << " trong danh sach!" << endl;
    }
    else
    {
        system("cls");
        cout << setw(106) << "THONG TIN MEO CO ID " << id << " LA:" << endl
             << endl;
        A[pos].Output();
        string sure;
        cout << setw(142) << "Ban co chac chan voi quyet dinh nay? (Go [ok] neu dong y va [nut khac de tro lai]): ";
        getline(cin >> ws, sure);
        if (sure == "OK" || sure == "ok" || sure == "Ok" || sure == "oK")
        {
            FOR(i, pos + 1, n)
            A[i - 1] = A[i];
            n = n - 1;
            cout << endl;
            cout << setw(108) << "Xoa thanh cong!!" << endl
                 << endl;
        }
        else
            return;
    }
}

void QLCAT::Update(string id)
{
    int i = 1;
    while (i <= n && A[i].getKey() != id)
        i++;

    if (i > n)
    {
        cout << endl;
        cout << setw(101) << "Khong ton tai id " << id << " trong danh sach!" << endl;
    }
    else
    {
        while (true)
        {
            system("cls");
            cout << setw(114) << "THONG TIN MEO CAN CHINH SUA:" << endl
                 << endl;
            A[i].Output();

            cout << setw(120) << "BAN MUON CHINH SUA THONG TIN NAO CUA MEO?" << endl
                 << endl;
            cout << setw(84) << "1.Ten" << setw(36) << "4.Can nang" << endl
                 << endl;
            cout << setw(85) << "2.Tuoi" << setw(16) << "0.Thoat" << setw(19) << "5.Mau long" << endl
                 << endl;
            cout << setw(90) << "3.Chieu cao" << setw(30) << "6.Chi so thuan hoa" << endl
                 << endl;

            cout << setw(111) << "Moi ban nhap lua chon: ";
            int chon;
            cin >> chon;

            if (chon == 1)
            {
                system("cls");
                A[i].Output();
                string UpdateName;
                cout << setw(112) << "Nhap ten muon chinh sua: ";
                getline(cin >> ws, UpdateName);
                A[i].SetBinomial_nomenclature(UpdateName);
                cout << endl;
                cout << setw(114) << "Chinh sua ten thanh cong" << endl;
                break;
            }
            else if (chon == 2)
            {
                system("cls");
                A[i].Output();
                float UpdateAge;
                cout << setw(113) << "Nhap tuoi muon chinh sua: ";
                cin >> UpdateAge;
                A[i].SetAgeold(UpdateAge);
                cout << endl;
                cout << setw(114) << "Chinh sua tuoi thanh cong" << endl;
                break;
            }
            else if (chon == 3)
            {
                system("cls");
                A[i].Output();
                float UpdateHeight;
                cout << setw(115) << "Nhap chieu cao muon chinh sua: ";
                cin >> UpdateHeight;
                A[i].SetHeight(UpdateHeight);
                cout << endl;
                cout << setw(116) << "Chinh sua chieu cao thanh cong" << endl;
                break;
            }
            else if (chon == 4)
            {
                system("cls");
                A[i].Output();
                float UpdateWeight;
                cout << setw(115) << "Nhap can nang muon chinh sua: ";
                cin >> UpdateWeight;
                A[i].SetWeight(UpdateWeight);
                cout << endl;
                cout << setw(116) << "Chinh sua can nang thanh cong" << endl;
                break;
            }
            else if (chon == 5)
            {
                system("cls");
                A[i].Output();
                string UpdateSkin;
                cout << setw(115) << "Nhap mau long muon chinh sua: ";
                getline(cin >> ws, UpdateSkin);
                A[i].SetSkincolor(UpdateSkin);
                cout << endl;
                cout << setw(116) << "Chinh sua mau long thanh cong" << endl;
                break;
            }
            else if (chon == 6)
            {
                system("cls");
                A[i].Output();
                float UpdateCSTH;
                cout << setw(119) << "Nhap chi so thuan hoa muon chinh sua: ";
                cin >> UpdateCSTH;
                A[i].SetThoroughbred_index(UpdateCSTH);
                cout << endl;
                cout << setw(120) << "Chinh sua chi so thuan hoa thanh cong" << endl;
                break;
            }
            else if (chon == 0)
                break;
            else
            {
                system("cls");
                A[i].Output();
                cout << setw(116) << "Lua chon khong hop le. Moi nhap lai" << endl;
                cout << setw(83) << " ";
                system("pause");
                continue;
            }
        }
    }
}

int QLCAT::SumPrice()
{
    int s;
    FOR(i, 1, n)
    s += (size_t)A[i].Price();
    return s;
}

long long QLCAT::getPrice_atpos(int pos)
{
    return A[pos].Price();
}

void QLCAT::getf()
{
    ifstream inp1;
    inp1.open("CAT.txt", ios_base::in);
    if (inp1.fail())
    {
        cout << "NOT FOUND!\n";
        system("pause");
        return;
    }
    int news;
    inp1 >> news;
    n = news;
    this->A = new Cat[n * 2 + 30];
    string a, b, f;
    int c;
    float d, e, g;
    int h;
    int i = 1;
    while (i != n + 1 && !inp1.eof())
    {
        getline(inp1 >> ws, a, ',');
        getline(inp1 >> ws, b, ',');
        inp1 >> c;
        inp1.ignore(1);
        inp1 >> d;
        inp1.ignore(1);
        inp1 >> e;
        inp1.ignore(1);
        getline(inp1 >> ws, f, ',');
        inp1 >> g;
        inp1.ignore(1);
        inp1 >> h;
        A[i].init1(a, b, c, d, e, f, g, h);
        i++;
    }
    inp1.close();
}

void QLCAT::writef()
{
    ofstream fileout;
    fileout.open("CAT.txt", ios::out);
    fileout << this->n;
    fileout << "\n\n";
    FOR(i, 1, n)
    {
        fileout << A[i].getKey() << ", "
                << A[i].GetBinomial_nomenclature() << ", "
                << A[i].GetAgeold() << ", "
                << A[i].GetHeight() << ", "
                << A[i].GetWeight() << ", "
                << A[i].GetSkincolor() << ", "
                << A[i].GetThoroughbred_index() << ", "
                << A[i].getNums() << endl;
        fileout << "\n";
    }
    fileout.close();
}

string QLCAT::getname_atpos(int pos)
{
    return A[pos].GetBinomial_nomenclature();
}

void QLCAT::show_forcat_Customer()
{
    cout << setw(45) << "+";
    FOR(i, 1, 101)
    cout << "-";
    cout << "+";
    cout << endl
         << setw(45) << "|" << setw(65) << "MENU CUA TIEM THU CUNG BAT ON" << setw(37) << "|" << endl;
    cout << setw(45) << "+";
    FOR(i, 1, 101)
    cout << "-";
    cout << "+";
    cout << endl;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i = i + 2)
        {
            cout << setw(44) << " "
                 << "+-----------------STT 0" << i << "-----------------+ \t\t\t +-----------------STT 0" << i + 1 << "-----------------+\n";
            cout << setw(44) << " "
                 << "| Ten meo: " << setw(30) << left << A[i].GetBinomial_nomenclature() << "|"
                 << "\t\t\t "
                 << "| Ten meo: " << setw(30) << left << A[i + 1].GetBinomial_nomenclature() << "|" << endl;
            cout << setw(44) << " "
                 << "| Tuoi: " << setw(33) << left << A[i].GetAgeold() << "|"
                 << "\t\t\t "
                 << "| Tuoi: " << setw(33) << left << A[i + 1].GetAgeold() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chieu cao: " << setw(28) << left << A[i].GetHeight() << "|"
                 << "\t\t\t "
                 << "| Chieu cao: " << setw(28) << left << A[i + 1].GetHeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Can nang: " << setw(29) << left << A[i].GetWeight() << "|"
                 << "\t\t\t "
                 << "| Can nang: " << setw(29) << left << A[i + 1].GetWeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Mau long: " << setw(29) << left << A[i].GetSkincolor() << "|"
                 << "\t\t\t "
                 << "| Mau long: " << setw(29) << left << A[i + 1].GetSkincolor() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chi so thuan hoa: " << setw(21) << left << A[i].GetThoroughbred_index() << "|"
                 << "\t\t\t "
                 << "| Chi so thuan hoa: " << setw(21) << left << A[i + 1].GetThoroughbred_index() << "|" << endl;
            cout << setw(44) << " "
                 << "| So luong co trong kho: " << setw(16) << left << A[i].getNums() << "|"
                 << "\t\t\t "
                 << "| So luong co trong kho: " << setw(16) << left << A[i + 1].getNums() << "|" << endl;
            cout << setw(44) << " "
                 << "| Gia: " << setw(34) << left << (size_t)A[i].Price() << "|"
                 << "\t\t\t "
                 << "| Gia: " << setw(34) << left << (size_t)A[i + 1].Price() << "|" << endl;
            cout << setw(44) << " "
                 << "+----------------------------------------+\t\t\t +----------------------------------------+";
            cout << endl
                 << endl;
        }
    }
    else
    {
        for (int i = 1; i <= n - 1; i = i + 2)
        {
            cout << setw(44) << " "
                 << "+-----------------STT 0" << i << "-----------------+ \t\t\t +-----------------STT 0" << i + 1 << "-----------------+\n";
            cout << setw(44) << " "
                 << "| Ten meo: " << setw(30) << left << A[i].GetBinomial_nomenclature() << "|"
                 << "\t\t\t "
                 << "| Ten meo: " << setw(30) << left << A[i + 1].GetBinomial_nomenclature() << "|" << endl;
            cout << setw(44) << " "
                 << "| Tuoi: " << setw(33) << left << A[i].GetAgeold() << "|"
                 << "\t\t\t "
                 << "| Tuoi: " << setw(33) << left << A[i + 1].GetAgeold() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chieu cao: " << setw(28) << left << A[i].GetHeight() << "|"
                 << "\t\t\t "
                 << "| Chieu cao: " << setw(28) << left << A[i + 1].GetHeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Can nang: " << setw(29) << left << A[i].GetWeight() << "|"
                 << "\t\t\t "
                 << "| Can nang: " << setw(29) << left << A[i + 1].GetWeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Mau long: " << setw(29) << left << A[i].GetSkincolor() << "|"
                 << "\t\t\t "
                 << "| Mau long: " << setw(29) << left << A[i + 1].GetSkincolor() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chi so thuan hoa: " << setw(21) << left << A[i].GetThoroughbred_index() << "|"
                 << "\t\t\t "
                 << "| Chi so thuan hoa: " << setw(21) << left << A[i + 1].GetThoroughbred_index() << "|" << endl;
            cout << setw(44) << " "
                 << "| So luong co trong kho: " << setw(16) << left << A[i].getNums() << "|"
                 << "\t\t\t "
                 << "| So luong co trong kho: " << setw(16) << left << A[i + 1].getNums() << "|" << endl;
            cout << setw(44) << " "
                 << "| Gia: " << setw(34) << left << (size_t)A[i].Price() << "|"
                 << "\t\t\t "
                 << "| Gia: " << setw(34) << left << (size_t)A[i + 1].Price() << "|" << endl;
            cout << setw(44) << " "
                 << "+----------------------------------------+\t\t\t +----------------------------------------+";
            cout << endl
                 << endl;
        }
        cout << setw(44) << " "
             << "+-----------------STT 0" << n << "-----------------+\n";
        cout << setw(44) << " "
             << "| Ten meo: " << setw(30) << left << A[n].GetBinomial_nomenclature() << "|" << endl;
        cout << setw(44) << " "
             << "| Tuoi: " << setw(33) << left << A[n].GetAgeold() << "|" << endl;
        cout << setw(44) << " "
             << "| Chieu cao: " << setw(28) << left << A[n].GetHeight() << "|" << endl;
        cout << setw(44) << " "
             << "| Can nang: " << setw(29) << left << A[n].GetWeight() << "|" << endl;
        cout << setw(44) << " "
             << "| Mau long: " << setw(29) << left << A[n].GetSkincolor() << "|" << endl;
        cout << setw(44) << " "
             << "| Chi so thuan hoa: " << setw(21) << left << A[n].GetThoroughbred_index() << "|" << endl;
        cout << setw(44) << " "
             << "| So luong co trong kho: " << setw(16) << left << A[n].getNums() << "|" << endl;
        cout << setw(44) << " "
             << "| Gia: " << setw(34) << left << (size_t)A[n].Price() << "|" << endl;
        cout << setw(44) << " "
             << "+----------------------------------------+\n"
             << endl;
    }
}

void QLCAT::MenuForCat()
{
    while (true)
    {
        system("cls");
        int opt;
        cout << setw(135) << "+-------------------------------------------------------------------+" << endl;
        cout << setw(135) << "|                     CHUONG TRINH QUAN LY MEO                      |" << endl;
        cout << setw(135) << "|1.Nhap thong tin meo                                               |" << endl;
        cout << setw(135) << "|2.Xuat thong tin meo                                               |" << endl;
        cout << setw(135) << "|3.Them thong tin meo vao cuoi danh sach                            |" << endl;
        cout << setw(135) << "|4.Tim thong tin meo theo id                                        |" << endl;
        cout << setw(135) << "|5.Xoa thong tin meo theo id                                        |" << endl;
        cout << setw(135) << "|6.Chinh sua thong tin theo id                                      |" << endl;
        cout << setw(135) << "|7.Tinh tong tien meo                                               |" << endl;
        cout << setw(135) << "|8.Doc du lieu meo tu file co san                                   |" << endl;
        cout << setw(135) << "|9.Ghi du lieu meo tu file co san                                   |" << endl;
        cout << setw(135) << "|0.Thoat chuong trinh                                               |" << endl;
        cout << setw(135) << "|                                END                                |" << endl;
        cout << setw(135) << "+-------------------------------------------------------------------+" << endl
             << endl;

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
        ///////////////////////0
        if (opt == 0)
            break;

        /////////////////////////1
        else if (opt == 1)
        {
            system("cls");
            QLCAT::init();
            cout << setw(103) << "DONE!!" << endl;
            cout << setw(83) << " ";
            system("pause");
        }
        ////////////////////////2
        else if (opt == 2)
        {
            system("cls");
            QLCAT::showforcat();
            cout << setw(83) << " ";
            system("pause");
        }
        /////////////////////////3
        else if (opt == 3)
        {
            system("cls");
            QLCAT::showforcat();
            string a, b, f;
            int c, h;
            float d, e, g;

            cout << setw(105) << "Nhap id muon them: ";
            getline(cin >> ws, a);

            if (this->n >= 1)
            {
                int *c = new int;
                while (1)
                {
                    *c = 0;
                    FOR(i, 1, this->n)
                    if (a == A[i].getKey())
                    {

                        *c = 1;

                        cout << endl;
                        cout << setw(124) << "ID DA TON TAI!! MOI BAN NHAP ID KHAC: ";

                        getline(cin >> ws, a);

                        break;
                    }
                    if (*c == 0)
                    {

                        delete c;
                        break;
                    }
                }
            }

            cout << setw(110) << "Nhap ten meo muon them: ";
            getline(cin >> ws, b);

            cout << setw(97) << "Nhap tuoi: ";
            cin >> c;

            cout << setw(102) << "Nhap chieu cao: ";
            cin >> d;

            cout << setw(101) << "Nhap can nang: ";
            cin >> e;

            cout << setw(101) << "Nhap mau long: ";
            getline(cin >> ws, f);

            cout << setw(109) << "Nhap chi so thuan hoa: ";
            cin >> g;

            cout << setw(114) << "Nhap so luong co trong kho: ";
            cin >> h;
            cout << endl;

            Cat *Z = new Cat();
            Z->init1(a, b, c, d, e, f, g, h);
            Z->setNums(h);
            A[++n] = *Z;
            A[n].setNums(h);

            delete Z;

            cout << endl;
            cout << setw(103) << "DONE!!" << endl
                 << endl;
            cout << setw(84) << " ";
            system("pause");
        }
        /////////////////////5
        else if (opt == 4)
        {
            system("cls");
            QLCAT::showforcat();
            string id;
            cout << setw(106) << "Nhap id muon tim: ";
            getline(cin >> ws, id);
            cout << endl;
            QLCAT::findcat(id);
            cout << endl;
            cout << setw(83) << " ";
            system("pause");
        }
        ////////////////////////6
        else if (opt == 5)
        {
            string id;
            system("cls");
            QLCAT::showforcat();
            cout << setw(111) << "Nhap id ban muon xoa: ";
            getline(cin >> ws, id);
            QLCAT::delete_atpos(id);
            cout << setw(86) << " ";
            system("pause");
        }

        else if (opt == 6)
        {
            system("cls");
            QLCAT::showforcat();
            string id;
            cout << setw(110) << "Nhap id muon chinh sua: ";
            getline(cin >> ws, id);
            QLCAT::Update(id);
            cout << endl;
            cout << setw(87) << " ";
            system("pause");
        }

        else if (opt == 7)
        {
            cout << setw(103) << "Tong tien la: " << (size_t)QLCAT::SumPrice() << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 8)
        {
            QLCAT::getf();
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 9)
        {
            QLCAT::writef();
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
////////////////////////////////////////////////////////////////////////////
QLDOG::QLDOG(int n)
{
    B = new Dog[n * n + 1];
}

QLDOG::~QLDOG()
{
    delete[] B;
}

int QLDOG::Getn()
{
    return this->n;
}

void QLDOG::Setn(int N)
{
    this->n = N;
}

int QLDOG::getsl_atpos(int pos)
{
    return B[pos].getNums();
}

void QLDOG::setsl_atpos(int pos, int sl)
{
    B[pos].setNums(sl);
}

void QLDOG::init()
{
    cout << setw(114) << "Nhap so luong cho muon them: ";
    int k;
    cin >> k;
    Dog *Z = new Dog();
    FOR(i, 1, k)
    {
        cout << endl;
        system("cls");
        cout << setw(114) << "NHAP THONG TIN LOAI CHO THU " << i << endl
             << endl;
        string s = "-";
        cout << setw(99) << "Nhap id cho: ";
        getline(cin >> ws, s);
        while (1)
        {
            if (s[0] != 'D')
            {
                cout << setw(129) << "Ki tu dau cua ID phai la D!, moi nhap lai: ";
                getline(cin >> ws, s);
            }
            else
                break;
        }
        while (1)
        {
            int ck = 0;
            FOR(j, 1, this->n)
            if (s == B[j].getKey())
            {
                cout << setw(123) << "ID DA BI TRUNG, MOI BAN NHAP LAI !:  ";
                ck = 1;
                getline(cin >> ws, s);
                while (1)
                {
                    if (s[0] != 'D')
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
        Z->setKey(s);
        Z->Input();
        QLDOG::add_dog(this->n, Z);
    }
    cout << endl;
}

void QLDOG::showfordog()
{
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    cout << setw(168) << "|    ID    |        TEN KHOA HOC        |  TUOI  | CHIEU CAO | CAN NANG |     MAU LONG     |  CSTH  |   SO LUONG   |    THANH TIEN    |\n";
    cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    FOR(i, 1, n)
    {
        cout << setw(33) << "|" << setw((10 - B[i].getKey().length()) / 2) << " " << B[i].getKey() << setw(10 - B[i].getKey().length() - (10 - B[i].getKey().length()) / 2) << " "
             << "|" << setw((28 - B[i].GetBinomial_nomenclature().length()) / 2) << " " << B[i].GetBinomial_nomenclature() << setw(28 - B[i].GetBinomial_nomenclature().length() - (28 - B[i].GetBinomial_nomenclature().length()) / 2) << " "
             << "|" << setw(5) << B[i].GetAgeold() << setw(4)
             << "|" << setw(7) << B[i].GetHeight() << setw(5)
             << "|" << setw(7) << B[i].GetWeight() << setw(4)
             << "|" << setw((18 - B[i].GetSkincolor().length()) / 2) << " " << B[i].GetSkincolor() << setw(18 - B[i].GetSkincolor().length() - (18 - B[i].GetSkincolor().length()) / 2) << " "
             << "|" << setw(6) << B[i].GetThoroughbred_index() << setw(3)
             << "|" << setw(8) << B[i].getNums() << setw(7)
             << "|" << setw(13) << (size_t)B[i].Price() << setw(6)
             << "|" << endl;
        cout << setw(168) << "+----------+----------------------------+--------+-----------+----------+------------------+--------+--------------+------------------+\n";
    }
    cout << endl;
}

void QLDOG::add_dog(int pos, Dog *Z)
{
    if (pos == n || pos == n + 1)
        B[++n] = *Z;
    else
    {
        FOD(i, n + 1, pos + 1)
        B[i] = B[i - 1];
        B[pos] = *Z;
        n++;
    }
}

long long QLDOG::getPrice_atpos(int pos)
{
    return B[pos].Price();
}

string QLDOG::getname_atpos(int pos)
{
    return B[pos].GetBinomial_nomenclature();
}

void QLDOG::find_dog(string id)
{
    int i = 1;
    while (i <= n && B[i].getKey() != id)
        i++;

    if (i == n + 1)
    {
        system("cls");
        QLDOG::showfordog();
        cout << setw(98) << "Khong ton tai id " << id << " trong danh sach!" << endl;
    }
    else
    {
        system("cls");
        cout << setw(106) << "Thong tin cho co id " << id << " la:" << endl;
        B[i].Output();
    }
}

void QLDOG::delete_atpos(string id)
{
    int pos = 1;
    while (pos <= n && B[pos].getKey() != id)
        pos++;

    if (pos > n)
    {
        cout << endl;
        cout << setw(98) << "Khong ton tai id " << id << " trong danh sach!" << endl;
    }
    else
    {
        system("cls");
        cout << setw(106) << "THONG TIN CHO CO ID " << id << " LA:" << endl
             << endl;
        B[pos].Output();
        string sure;
        cout << setw(142) << "Ban co chac chan voi quyet dinh nay? (Go [ok] neu dong y va [nut khac de tro lai]): ";
        getline(cin >> ws, sure);
        if (sure == "OK" || sure == "ok" || sure == "Ok" || sure == "oK")
        {
            FOR(i, pos + 1, n)
            B[i - 1] = B[i];
            n = n - 1;
            cout << endl;
            cout << setw(108) << "Xoa thanh cong!!" << endl
                 << endl;
        }
        else
            return;
    }
}

void QLDOG::Update(string id)
{
    int i = 1;
    while (i <= n && B[i].getKey() != id)
        i++;

    if (i > n)
    {
        cout << endl;
        cout << setw(101) << "Khong ton tai id " << id << " trong danh sach!" << endl;
    }
    else
    {
        while (true)
        {
            system("cls");
            cout << setw(114) << "THONG TIN CHO CAN CHINH SUA:" << endl;
            B[i].Output();

            cout << setw(120) << "BAN MUON CHINH SUA THONG TIN NAO CUA CHO?" << endl
                 << endl;
            cout << setw(84) << "1.Ten" << setw(36) << "4.Can nang" << endl
                 << endl;
            cout << setw(85) << "2.Tuoi" << setw(16) << "0.Thoat" << setw(19) << "5.Mau long" << endl
                 << endl;
            cout << setw(90) << "3.Chieu cao" << setw(30) << "6.Chi so thuan hoa" << endl
                 << endl;
            cout << setw(111) << "Moi ban nhap lua chon: ";
            int chon;
            cin >> chon;

            if (chon == 1)
            {
                system("cls");
                B[i].Output();
                string UpdateName;
                cout << setw(112) << "Nhap ten muon chinh sua: ";
                getline(cin >> ws, UpdateName);
                B[i].SetBinomial_nomenclature(UpdateName);
                cout << endl;
                cout << setw(114) << "Chinh sua ten thanh cong" << endl;
                break;
            }
            else if (chon == 2)
            {
                system("cls");
                B[i].Output();
                float UpdateAge;
                cout << setw(113) << "Nhap tuoi muon chinh sua: ";
                cin >> UpdateAge;
                B[i].SetAgeold(UpdateAge);
                cout << endl;
                cout << setw(114) << "Chinh sua tuoi thanh cong" << endl;
                break;
            }
            else if (chon == 3)
            {
                system("cls");
                B[i].Output();
                float UpdateHeight;
                cout << setw(115) << "Nhap chieu cao muon chinh sua: ";
                cin >> UpdateHeight;
                B[i].SetHeight(UpdateHeight);
                cout << endl;
                cout << setw(116) << "Chinh sua chieu cao thanh cong" << endl;
                break;
            }
            else if (chon == 4)
            {
                system("cls");
                B[i].Output();
                float UpdateWeight;
                cout << setw(115) << "Nhap can nang muon chinh sua: ";
                cin >> UpdateWeight;
                B[i].SetWeight(UpdateWeight);
                cout << endl;
                cout << setw(116) << "Chinh sua can nang thanh cong" << endl;
                break;
            }
            else if (chon == 5)
            {
                system("cls");
                B[i].Output();
                string UpdateSkin;
                cout << setw(115) << "Nhap mau long muon chinh sua: ";
                getline(cin >> ws, UpdateSkin);
                B[i].SetSkincolor(UpdateSkin);
                cout << endl;
                cout << setw(116) << "Chinh sua mau long thanh cong" << endl;
                break;
            }
            else if (chon == 6)
            {
                system("cls");
                B[i].Output();
                float UpdateCSTH;
                cout << setw(119) << "Nhap chi so thuan hoa muon chinh sua: ";
                cin >> UpdateCSTH;
                B[i].SetThoroughbred_index(UpdateCSTH);
                cout << endl;
                cout << setw(120) << "Chinh sua chi so thuan hoa thanh cong" << endl;
                break;
            }
            else if (chon == 0)
                break;
            else
            {
                system("cls");
                B[i].Output();
                cout << setw(116) << "Lua chon khong hop le. Moi nhap lai" << endl;
                cout << setw(83) << " ";
                system("pause");
                continue;
            }
        }
    }
}

long long QLDOG::SumPrice()
{
    long long s;
    FOR(i, 1, n)
    s = s + (size_t)(B[i].Price() * B[i].getNums());
    return s;
}

void QLDOG::getf()
{
    ifstream inp1;
    inp1.open("DOG.txt", ios_base::in);
    if (inp1.fail())
    {
        cout << "NOT FOUND!\n";
        system("pause");
        return;
    }
    string a, b, f;
    int c, h;
    float d, e, g;
    int i = 1;
    int size;
    inp1 >> size;
    n = size;
    delete[] this->B;
    B = new Dog[n * n + 10];
    while (i != n + 1 && !inp1.eof())
    {
        getline(inp1 >> ws, a, ',');
        getline(inp1 >> ws, b, ',');
        inp1 >> c;
        inp1.ignore(1);
        inp1 >> d;
        inp1.ignore(1);
        inp1 >> e;
        inp1.ignore(1);
        getline(inp1 >> ws, f, ',');
        inp1 >> g;
        inp1.ignore(1);
        inp1 >> h;
        B[i].init1(a, b, c, d, e, f, g, h);
        i++;
    }
    inp1.close();
}

void QLDOG::writef()
{
    ofstream fileout;
    fileout.open("DOG.txt", ios::out);
    fileout << this->n;
    fileout << "\n\n";
    FOR(i, 1, n)
    {
        fileout << B[i].getKey() << ", "
                << B[i].GetBinomial_nomenclature() << ", "
                << B[i].GetAgeold() << ", "
                << B[i].GetHeight() << ", "
                << B[i].GetWeight() << ", "
                << B[i].GetSkincolor() << ", "
                << B[i].GetThoroughbred_index() << ", "
                << B[i].getNums() << endl;
        fileout << "\n";
    }

    fileout.close();
}

void QLDOG::show_fordog_Customer()
{
    cout << setw(45) << "+";
    FOR(i, 1, 101)
    cout << "-";
    cout << "+";
    cout << endl
         << setw(45) << "|" << setw(65) << "MENU CUA TIEM THU CUNG BAT ON" << setw(37) << "|" << endl;
    cout << setw(45) << "+";
    FOR(i, 1, 101)
    cout << "-";
    cout << "+";
    cout << endl;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i = i + 2)
        {
            cout << setw(44) << " "
                 << "+-----------------STT 0" << i << "-----------------+ \t\t\t +-----------------STT 0" << i + 1 << "-----------------+\n";
            cout << setw(44) << " "
                 << "| Ten cho: " << setw(30) << left << B[i].GetBinomial_nomenclature() << "|"
                 << "\t\t\t "
                 << "| Ten cho: " << setw(30) << left << B[i + 1].GetBinomial_nomenclature() << "|" << endl;
            cout << setw(44) << " "
                 << "| Tuoi: " << setw(33) << left << B[i].GetAgeold() << "|"
                 << "\t\t\t "
                 << "| Tuoi: " << setw(33) << left << B[i + 1].GetAgeold() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chieu cao: " << setw(28) << left << B[i].GetHeight() << "|"
                 << "\t\t\t "
                 << "| Chieu cao: " << setw(28) << left << B[i + 1].GetHeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Can nang: " << setw(29) << left << B[i].GetWeight() << "|"
                 << "\t\t\t "
                 << "| Can nang: " << setw(29) << left << B[i + 1].GetWeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Mau long: " << setw(29) << left << B[i].GetSkincolor() << "|"
                 << "\t\t\t "
                 << "| Mau long: " << setw(29) << left << B[i + 1].GetSkincolor() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chi so thuan hoa: " << setw(21) << left << B[i].GetThoroughbred_index() << "|"
                 << "\t\t\t "
                 << "| Chi so thuan hoa: " << setw(21) << left << B[i + 1].GetThoroughbred_index() << "|" << endl;
            cout << setw(44) << " "
                 << "| So luong co trong kho: " << setw(16) << left << B[i].getNums() << "|"
                 << "\t\t\t "
                 << "| So luong co trong kho: " << setw(16) << left << B[i + 1].getNums() << "|" << endl;
            cout << setw(44) << " "
                 << "| Gia: " << setw(34) << left << (size_t)B[i].Price() << "|"
                 << "\t\t\t "
                 << "| Gia: " << setw(34) << left << (size_t)B[i + 1].Price() << "|" << endl;
            cout << setw(44) << " "
                 << "+----------------------------------------+\t\t\t +----------------------------------------+";
            cout << endl
                 << endl;
        }
    }
    else
    {
        for (int i = 1; i <= n - 1; i = i + 2)
        {
            cout << setw(44) << " "
                 << "+-----------------STT 0" << i << "-----------------+ \t\t\t +-----------------STT 0" << i + 1 << "-----------------+\n";
            cout << setw(44) << " "
                 << "| Ten cho: " << setw(30) << left << B[i].GetBinomial_nomenclature() << "|"
                 << "\t\t\t "
                 << "| Ten cho: " << setw(30) << left << B[i + 1].GetBinomial_nomenclature() << "|" << endl;
            cout << setw(44) << " "
                 << "| Tuoi: " << setw(33) << left << B[i].GetAgeold() << "|"
                 << "\t\t\t "
                 << "| Tuoi: " << setw(33) << left << B[i + 1].GetAgeold() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chieu cao: " << setw(28) << left << B[i].GetHeight() << "|"
                 << "\t\t\t "
                 << "| Chieu cao: " << setw(28) << left << B[i + 1].GetHeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Can nang: " << setw(29) << left << B[i].GetWeight() << "|"
                 << "\t\t\t "
                 << "| Can nang: " << setw(29) << left << B[i + 1].GetWeight() << "|" << endl;
            cout << setw(44) << " "
                 << "| Mau long: " << setw(29) << left << B[i].GetSkincolor() << "|"
                 << "\t\t\t "
                 << "| Mau long: " << setw(29) << left << B[i + 1].GetSkincolor() << "|" << endl;
            cout << setw(44) << " "
                 << "| Chi so thuan hoa: " << setw(21) << left << B[i].GetThoroughbred_index() << "|"
                 << "\t\t\t "
                 << "| Chi so thuan hoa: " << setw(21) << left << B[i + 1].GetThoroughbred_index() << "|" << endl;
            cout << setw(44) << " "
                 << "| So luong co trong kho: " << setw(16) << left << B[i].getNums() << "|"
                 << "\t\t\t "
                 << "| So luong co trong kho: " << setw(16) << left << B[i + 1].getNums() << "|" << endl;
            cout << setw(44) << " "
                 << "| Gia: " << setw(34) << left << (size_t)B[i].Price() << "|"
                 << "\t\t\t "
                 << "| Gia: " << setw(34) << left << (size_t)B[i + 1].Price() << "|" << endl;
            cout << setw(44) << " "
                 << "+----------------------------------------+\t\t\t +----------------------------------------+";
            cout << endl
                 << endl;
        }
        cout << setw(44) << " "
             << "+-----------------STT 0" << n << "-----------------+\n";
        cout << setw(44) << " "
             << "| Ten cho: " << setw(30) << left << B[n].GetBinomial_nomenclature() << "|" << endl;
        cout << setw(44) << " "
             << "| Tuoi: " << setw(33) << left << B[n].GetAgeold() << "|" << endl;
        cout << setw(44) << " "
             << "| Chieu cao: " << setw(28) << left << B[n].GetHeight() << "|" << endl;
        cout << setw(44) << " "
             << "| Can nang: " << setw(29) << left << B[n].GetWeight() << "|" << endl;
        cout << setw(44) << " "
             << "| Mau long: " << setw(29) << left << B[n].GetSkincolor() << "|" << endl;
        cout << setw(44) << " "
             << "| Chi so thuan hoa: " << setw(21) << left << B[n].GetThoroughbred_index() << "|" << endl;
        cout << setw(44) << " "
             << "| So luong co trong kho: " << setw(16) << left << B[n].getNums() << "|" << endl;
        cout << setw(44) << " "
             << "| Gia: " << setw(34) << left << (size_t)B[n].Price() << "|" << endl;
        cout << setw(44) << " "
             << "+----------------------------------------+\n"
             << endl;
    }
}

void QLDOG::MenuFordog()
{
    while (1)
    {
        int opt;
        system("cls");
        cout << setw(145) << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
        cout << setw(145) << "|                                CHUONG TRINH QUAN LY CHO                               |" << endl;
        cout << setw(145) << "|                                                                                       |" << endl;
        cout << setw(145) << "|1.Nhap thong tin cho                          6.Chinh sua thong tin cho theo id        |" << endl;
        cout << setw(145) << "|2.Xuat thong tin cho                          7.Tinh tong tien cua cho                 |" << endl;
        cout << setw(145) << "|3.Them thong tin cho vao cuoi danh sach       8.Doc DU LIEU TU FILE CO SAN             |" << endl;
        cout << setw(145) << "|4.Tim thong tin cho theo id                   9.GHI DU LIEU TU FILE CO SAN             |" << endl;
        cout << setw(145) << "|5.Xoa thong tin cho theo id                   0.THOAT                                  |" << endl;
        cout << setw(145) << "|                                                                                       |" << endl;
        cout << setw(145) << "|                                          END                                          |" << endl;
        cout << setw(145) << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl
             << endl;

        cout << setw(115) << "Moi ban nhap (lai) lua chon: ";
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
        /////////////////////////0
        if (opt == 0)
            break;

        else if (opt == 1)
        {
            system("cls");
            QLDOG::init();
            cout << setw(103) << "DONE!!" << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 2)
        {
            QLDOG::showfordog();
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 3)
        {
            system("cls");
            QLDOG::showfordog();

            string a, b, f;
            int c, h;
            float d, e, g;

            cout << setw(105) << "Nhap id muon them: ";
            getline(cin >> ws, a);

            if (this->n >= 1)
            {
                int *c = new int;
                while (1)
                {
                    *c = 0;
                    FOR(i, 1, this->n)
                    if (a == B[i].getKey())
                    {
                        cout << endl;
                        cout << setw(124) << "ID DA TON TAI!! MOI BAN NHAP ID KHAC: ";
                        getline(cin >> ws, a);
                        *c = 1;
                        break;
                    }
                    if (*c == 0)
                    {
                        break;
                        delete c;
                    }
                }
            }

            cout << setw(110) << "Nhap ten cho muon them: ";
            getline(cin >> ws, b);

            cout << setw(97) << "Nhap tuoi: ";
            cin >> c;

            cout << setw(102) << "Nhap chieu cao: ";
            cin >> d;

            cout << setw(101) << "Nhap can nang: ";
            cin >> e;

            cout << setw(101) << "Nhap mau long: ";
            getline(cin >> ws, f);

            cout << setw(109) << "Nhap chi so thuan hoa: ";
            cin >> g;

            cout << setw(114) << "Nhap so luong co trong kho: ";
            cin >> h;
            cout << endl;
            Dog *Z = new Dog();
            Z->init1(a, b, c, d, e, f, g, h);

            QLDOG::add_dog(n, Z);

            delete Z;
            cout << endl;
            cout << setw(103) << "DONE!!" << endl
                 << endl;
            cout << setw(84) << " ";
            system("pause");
        }

        else if (opt == 4)
        {
            system("cls");
            QLDOG::showfordog();
            string id;
            cout << setw(106) << "Nhap id muon tim: ";
            getline(cin >> ws, id);
            cout << endl;
            QLDOG::find_dog(id);
            cout << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 5)
        {
            string id;
            system("cls");
            QLDOG::showfordog();
            cout << endl;
            cout << setw(111) << "Nhap id ban muon xoa: ";
            getline(cin >> ws, id);
            QLDOG::delete_atpos(id);
            cout << setw(86) << " ";
            system("pause");
        }

        else if (opt == 6)
        {
            system("cls");
            QLDOG::showfordog();
            string id;
            cout << setw(110) << "Nhap id muon chinh sua: ";
            getline(cin >> ws, id);
            QLDOG::Update(id);
            cout << endl;
            cout << setw(87) << " ";
            system("pause");
        }

        else if (opt == 7)
        {

            cout << setw(103) << "Tong tien la: " << (size_t)QLDOG::SumPrice() << endl;
            cout << setw(83) << " ";
            system("pause");
        }

        else if (opt == 8)
        {

            QLDOG::getf();
            cout << setw(83) << " ";
            system("pause");
        }
        else if (opt == 9)
        {

            QLDOG::writef();
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
