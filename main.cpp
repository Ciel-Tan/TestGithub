#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "shopmanage.h"
#include "QLNV.h"
#include "QLKH.h"
#include "Receipt.h"
#include "ArrayofFinance.h"
#include <fstream>
using namespace std;
using std::string;
typedef long long ll;
typedef pair<int, int> ii;

/// ANSI ESCAPE CODE
///  contain kt : getline(cin>>ws, ss);
///"int k = (c) ? a : b" -> k = a (neu c dung) else = b
#define back_1line cout << "\033[F"
#define down_1line cout << "\033[B"
#define _CRT_SECURE_NO_WARNINGS_
// #define X first
// #define Y second
#define FORE(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define faster(x)                \
    ios::sync_with_stdio(false); \
    cin.tie(x);                  \
    cout.tie(x);
#define FI(x) freopen(x ".INP", "r", stdin)
#define FO(x) freopen(x ".OUT", "w", stdout)

string takePasswdFromUser()
{
    HANDLE hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;

    // Create a restore point Mode
    // is know 503
    GetConsoleMode(hStdInput, &mode);

    // Enable echo input
    // set to 499
    SetConsoleMode(
        hStdInput,
        mode & (~ENABLE_ECHO_INPUT));

    // Take input
    string ipt;
    getline(cin >> ws, ipt);

    // Otherwise next cout will print
    // into the same line
    cout << endl;

    // Restore the mode
    SetConsoleMode(hStdInput, mode);

    return ipt;
}

string takePasswdFromUser1()
{
    string ipt = "";
    char ipt_ch;
    while (true)
    {
        ipt_ch = getch();
        cout << "*";
        // Check whether user enters
        // a special non-printable
        // character
        if (ipt_ch < 32)
        {
            cout << endl;
            return ipt;
        }
        ipt.push_back(ipt_ch);
    }
}

int main()
{
    QLCAT *p = new QLCAT(100);
    QLDOG *q = new QLDOG(100);
    QLNV R;
    QLKH *T = new QLKH(100);
    FinanceManage *Y = new FinanceManage();

    T->setL(0);

    int choice, n, m;

    p->getf();
    q->getf();
    T->file_readKH();
    R.file_initEMP();
    Y->FinitF();

    while (1)
    {
        system("cls");

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 13);
        cout << "\n";
        cout << setw(82) << "=========";

        cout << "\x1b[1;30m CHUONG";
        Sleep(100);

        cout << "\x1b[1;31m TRINH";
        Sleep(100);

        cout << "\x1b[1;32m QUAN";
        Sleep(100);

        cout << "\x1b[1;33m LI";
        Sleep(100);

        cout << "\x1b[1;34m SHOP";
        Sleep(100);

        cout << "\x1b[1;35m THU";
        Sleep(100);

        cout << "\x1b[1;36m CUNG ";
        SetConsoleTextAttribute(hConsole, 13);
        cout << setw(82) << left << "=========" << endl
             << endl;

        cout << setw(89) << " "
             << "1: DANH CHO KHACH HANG" << endl;
        cout << setw(89) << " "
             << "2: DANH CHO QUAN LY" << endl;
        cout << setw(89) << " "
             << "Other Key: Thoat CT." << endl
             << endl;
        cout << setw(127) << right << "======================================================" << endl
             << endl;
        cout << setw(108) << right << "MOI NHAP LUA CHON: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            int total = 0;
            string a, c;
            int *xx = new int;
            Customer *khach = new Customer();
            *xx = 0;
            cout << endl;
            while (true)
            {
                cout << setw(106) << "\x1b[1;34m NHAP SDT: ";
                getline(cin >> ws, c);
                if (c.size() == 10)
                    break;
                cout << endl;
                SetConsoleTextAttribute(hConsole, 12);
                cout << setw(123) << "SDT phai co 10 chu so va khong chua ki tu nao!" << endl
                     << endl;
            }
            int pos = T->find_phone(c);

            if (pos != -1)
            {
                cout << endl;
                cout << setw((172 - T->getname_atpos(pos).length()) / 2) << " "
                     << "Chao mung " << T->getname_atpos(pos) << " da quay tro lai!" << endl
                     << endl;
                cout << setw(80);
                FOR(i, 1, 40)
                cout << "=";
                Date b;
                cin >> b;
                khach->init(T->get_id_atpos(pos), c, T->getname_atpos(pos), b, T->get_timeatpos(pos) + 1);
                T->inc_time_atpos(pos);
                cout << endl
                     << endl;
                cout << setw(83) << " ";
                system("pause");
            }

            else
            {
                cout << endl;
                cout << setw(118) << "\x1b[1;33m Ban la khach hang moi!!" << endl
                     << endl;
                cout << setw(102) << "NHAP HO TEN: ";
                getline(cin >> ws, a);
                cout << endl
                     << endl;
                cout << setw(81);
                FOR(i, 1, 40)
                cout << "=";
                Date b;
                cin >> b;
                *xx = 1;
                khach->init(rand() % 89999 + 10001, c, a, b, 1);
            }

            int dogbuy_sl[1005];
            int catbuy_sl[1005];
            memset(dogbuy_sl, 0, sizeof dogbuy_sl);
            memset(catbuy_sl, 0, sizeof catbuy_sl);
            while (true)
            {
                system("cls");
                SetConsoleTextAttribute(hConsole, 3);

                int choice_type;
                cout << setw(117) << "Moi ban chon loai con vat muon mua" << endl
                     << endl;
                cout << setw(88) << "1.Cho" << endl;
                cout << setw(88) << "2.Meo" << endl;
                cout << setw(119) << "3.In ra danh sach vua mua va hoa don" << endl;
                cout << setw(90) << "0.Thoat" << endl
                     << endl;
                cout << setw(106) << "Nhap lua chon cua ban: ";
                cin >> choice_type;

                Receipt bill;

                if (choice_type == 1)
                {
                    while (true)
                    {
                        system("cls");
                        q->show_fordog_Customer();
                        int stt_choice, sl = 0;

                        cout << setw(118) << right << "Nhap STT cua thu cung ban muon mua: ";
                        cin >> stt_choice;

                        if (stt_choice < 1 || stt_choice > q->Getn())
                        {
                            cout << endl;
                            cout << setw(103) << "MENU CHI CO " << q->Getn() << " SET" << endl
                                 << endl;
                            cout << setw(83) << " ";
                            system("pause");
                        }
                        else
                        {
                            cout << endl;
                            cout << setw(110) << "Nhap so luong muon mua: ";
                            cin >> sl;

                            if (sl > q->getsl_atpos(stt_choice))
                            {
                                cout << endl;
                                cout << setw(124) << "So luong nhap vuot qua luong con lai trong kho!!" << endl
                                     << endl;
                                cout << setw(83) << " ";
                                system("pause");
                                continue;
                            }

                            else
                            {
                                dogbuy_sl[stt_choice] += sl;
                                q->setsl_atpos(stt_choice, q->getsl_atpos(stt_choice) - sl);
                                khach->dogbuy[++khach->ndog] = stt_choice;
                                cout << endl;
                                cout << setw(116) << "Mua thanh cong cam on quy khach\n"
                                     << endl;
                                cout << setw(83) << " ";
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }

                    char c;
                    while (1)
                    {
                        system("cls");
                        cout << endl;
                        cout << setw(127) << "Ban muon mua tiep khong(y for 'yes', n for 'no' ): ";
                        cin >> c;
                        if (c == 'y')
                            break;
                        else if (c == 'n')
                        {
                            // con = 0;
                            break;
                        }
                        else
                        {
                            cout << endl;
                            cout << setw(119) << "Lua chon khong hop le moi ban nhap lai" << endl;
                            cout << setw(83) << " ";
                            system("pause");
                        }
                    }
                    cout << endl;
                    cout << setw(83) << " ";
                    system("pause");
                }
                else if (choice_type == 2)
                {
                    while (true)
                    {
                        system("cls");
                        p->show_forcat_Customer();
                        int stt_choice, sl = 0;
                        cout << setw(118) << right << "Nhap STT cua thu cung ban muon mua: ";
                        cin >> stt_choice;
                        if (stt_choice < 1 || stt_choice > p->Getn())
                        {
                            cout << endl;
                            cout << setw(103) << "MENU CHI CO " << p->Getn() << " SET" << endl
                                 << endl;
                            cout << setw(83) << " ";
                            system("pause");
                        }
                        else
                        {
                            cout << endl;
                            cout << setw(110) << "Nhap so luong muon mua: ";
                            cin >> sl;

                            if (sl > p->getsl_atpos(stt_choice))
                            {
                                cout << endl;
                                cout << setw(124) << "So luong nhap vuot qua luong con lai trong kho!!" << endl
                                     << endl;
                                cout << setw(83) << " ";
                                system("pause");
                                continue;
                            }
                            else
                            {
                                catbuy_sl[stt_choice] += sl;
                                p->setsl_atpos(stt_choice, p->getsl_atpos(stt_choice) - sl);
                                khach->catbuy[++khach->ncat] = stt_choice;
                                cout << endl;
                                cout << setw(116) << "Mua thanh cong cam on quy khach\n"
                                     << endl;
                                cout << setw(83) << " ";
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }

                    char c;

                    while (1)
                    {
                        system("cls");
                        cout << endl;
                        cout << setw(127) << "Ban muon mua tiep khong ? (y for 'yes', n for 'no' ): ";
                        cin >> c;
                        if (c == 'y')
                            break;
                        else if (c == 'n')
                        {
                            // con = 0;
                            break;
                        }
                        else
                        {
                            cout << endl;
                            cout << setw(119) << "Lua chon khong hop le moi ban nhap lai" << endl;
                            cout << setw(83) << " ";
                            system("pause");
                        }
                    }
                    cout << endl;
                    cout << setw(83) << " ";
                    system("pause");
                }
                else if (choice_type == 3)
                {
                    system("cls");
                    cout << setw(114) << "THONG TIN KHACH HANG VUA MUA:" << endl;
                    khach->display();
                    if (*xx == 1)
                        T->addtail(khach);

                    *xx = 0;

                    cout << endl
                         << endl;
                    bill.HD_print(p, q, khach, dogbuy_sl, catbuy_sl, *Y);

                    cout << endl;
                    cout << setw(83) << " ";
                    system("pause");
                }
                else if (choice_type == 0)
                {
                    bill.HD_OUT(p, q, khach, dogbuy_sl, catbuy_sl, *Y);
                    khach->ncat = khach->ndog = 0;
                    break;
                }
                else
                {
                    cout << endl;
                    cout << setw(121) << "Lua chon khong hop le. Moi ban nhap lai!!!" << endl;
                    cout << setw(83) << " ";
                    system("pause");
                }
            }
        }

        else if (choice == 2)
        {
            system("cls");
            // SetConsoleTextAttribute(hConsole, 3);

            Sleep(50);
            cout << setw(112) << "\x1b[1;36mDANG NHAP DANH CHO ADMIN" << endl
                 << endl;

            Sleep(50);
            cout << setw(81) << " "
                 << "@Username: Admin" << endl;

            Sleep(50);
            cout << setw(81) << " "
                 << "@Root Passcode for EMP >>> ";

            string pass = takePasswdFromUser1();
            string correct = "123456789";

            cout << endl
                 << endl;
            /// % loading password
            for (int i = 15; i <= 100; i += 5)
            {

                SetConsoleTextAttribute(hConsole, (rand() % 15) + 1);

                cout << setw(81) << " " << i << " % Loading...";

                FOR(i, 1, 100)
                cout << "\b";
                Sleep(70);
                if (i == 90 || i == 50 || i == 95 || i == 80)
                {
                    Sleep(150);
                }
            }
            cout << endl
                 << endl;
            // cout << "PASSWORD IS NOW DECRYPTING>>>\n";
            // FOR(i, 1, 15)
            // {
            //     SetConsoleTextAttribute(hConsole, (rand() % 15) + 1);
            //     cout << "=====";
            //     Sleep(80);
            // }

            // FOR(i, 1, 8)
            // {
            //     down_1line;
            //     cout << "\033[2D";
            //     SetConsoleTextAttribute(hConsole, (rand() % 15) + 1);
            //     cout << "||";
            //     Sleep(120);
            // }
            // cout << endl;
            // FOR(i, 1, 15)
            // {
            //     SetConsoleTextAttribute(hConsole, (rand() % 15) + 1);
            //     cout << left;
            //     cout << "=====";
            //     Sleep(80);
            // }

            // FOR(i, 1, 8)
            // {
            //     back_1line;
            //     SetConsoleTextAttribute(hConsole, (rand() % 15) + 1);
            //     cout << "||";
            //     Sleep(120);
            // }

            // FOR(i, 1, 10)
            // down_1line;

            if (pass == correct)
            {
                cout << endl;
                cout << setw(108) << "PASSWORD IS CORRECT!!!" << endl;
                cout << setw(81) << " ";
                system("pause");
                // Cat *Z = new Cat[100];
                int n, m;
                while (true)
                {
                    SetConsoleTextAttribute(hConsole, 11);

                    int opt;
                    system("cls");
                    Sleep(35);
                    cout << setw(134) << "+-----------------------------------------------------------------+" << endl;
                    Sleep(35);
                    cout << setw(134) << "|                CHUONG TRINH QUAN LY SHOP CHO MEO                |" << endl;
                    Sleep(35);
                    cout << setw(134) << "|1.Quan ly pet                                                    |" << endl;
                    Sleep(35);
                    cout << setw(134) << "|2.Quan ly nhan vien                                              |" << endl;
                    Sleep(35);
                    cout << setw(134) << "|3.Quan ly khach hang                                             |" << endl;
                    Sleep(35);
                    cout << setw(134) << "|4.Quan ly doanh thu                                              |" << endl;
                    Sleep(35);
                    cout << setw(134) << "|-1.Thoat chuong trinh                                            |" << endl;
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
                    if (opt == 1)
                    {
                        while (true)
                        {
                            system("cls");
                            int chon;
                            Sleep(50);
                            cout << setw(115) << "Ban muon quan ly cho hay meo?" << endl
                                 << endl;

                            Sleep(50);
                            cout << setw(107) << "1.Quan ly cho" << endl;

                            Sleep(50);
                            cout << setw(107) << "2.Quan ly meo" << endl;

                            Sleep(50);
                            cout << setw(94) << " "
                                 << "0.Thoat" << endl
                                 << endl;

                            Sleep(50);
                            cout << setw(112) << "Moi ban nhap lua chon: ";

                            cin >> chon;
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
                            if (chon == 1)
                            {
                                SetConsoleTextAttribute(hConsole, 10);
                                q->MenuFordog();
                            }

                            else if (chon == 2)
                            {
                                SetConsoleTextAttribute(hConsole, 12);
                                p->MenuForCat();
                            }

                            else if (chon == 0)
                                break;

                            else
                            {
                                cout << endl;
                                cout << setw(121) << "Lua chon khong hop le!!! Moi ban nhap lai" << endl
                                     << endl;
                                cout << setw(83) << " ";
                                system("pause");
                            }

                            /////////
                        }
                    }
                    else if (opt == 2)
                    {
                        R.menu_emp();
                    }
                    else if (opt == 0 || opt > 4 || opt < -1)
                    {
                        cout << endl;
                        cout << setw(121) << "Lua chon khong hop le!!! Moi ban nhap lai" << endl;
                        cout << setw(83) << " ";
                        system("pause");
                        continue;
                    }

                    else if (opt == 3)
                    {
                        T->menu_for_QLKH();
                        cout << setw(83) << " ";
                        system("pause");
                    }

                    else if (opt == 4)
                    {
                        /*Y->setatdate(4,2003,999);
                        cout << Y->getatdate(4,2003) << endl;
                        Y->displayat(4,2003);*/
                        Y->memu();
                        system("pause");
                    }

                    else if (opt == -1)
                    {
                        cout << endl;
                        cout << setw(109) << "HAVE A NICE DAY!!!";
                        break;
                    }
                }
            }
            else
            {
                cout << endl;
                cout << setw(103) << "WRONG PASS!" << endl;
                cout << setw(81) << " ";
                system("pause");
            }
        }
        // cout << T.find_info(Z);
        else
        {
            q->writef();
            p->writef();
            T->writeF();
            R.writef();
            Y->writeF();
            cout << endl;
            cout << setw(113) << "\x1b[4;35m HACK A NICE DAY!!!";
            break;
        }
    }
}