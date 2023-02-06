#ifndef ARRAYOFFINANCE_H
#define ARRAYOFFINANCE_H

#include "finance.h"

class FinanceManage
{
private:
    turnover *E = new turnover[12605];

public:
    FinanceManage();
    ~FinanceManage();
    long long getatdate(int, int);
    void display();
    void setatdate(int, int, long long);
    void displayat(int, int);
    void FinitF();
    void writeF();
    void memu();

    long long FinanceAt(int, int);
};

#endif